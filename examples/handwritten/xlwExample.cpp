
/*
 Copyright (C) 1998, 1999, 2001, 2002 J�r�me Lecomte
 Copyright (C) 2007, 2008 Eric Ehlers

 This file is part of xlw, a free-software/open-source C++ wrapper of the
 Excel C API - http://xlw.sourceforge.net/

 xlw is free software: you can redistribute it and/or modify it under the
 terms of the xlw license.  You should have received a copy of the
 license along with this program; if not, please email xlw-users@lists.sf.net

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

// $Id: xlwExample.cpp,v 1.12 2003/03/08 22:21:02 jlecomte Exp $

#include <xlw/xlw.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <xlw/Win32StreamBuf.h>

using namespace xlw;

Win32StreamBuf debuggerStreamBuf;
std::streambuf *oldStreamBuf;

extern "C"
{

    /*LPXLOPER*/ LPXLFOPER EXCEL_EXPORT xlCirc(XlfOper xlDiam)
    {
        EXCEL_BEGIN;
        // Converts d to a double.
        double ret=xlDiam.AsDouble();
        // Multiplies it.
        ret *= 3.14159;
        // Returns the result as an XlfOper.
        return XlfOper(ret);
        EXCEL_END;
    }

    /*LPXLOPER*/ LPXLFOPER EXCEL_EXPORT xlConcat(XlfOper xlStr1, XlfOper xlStr2)
    {
        EXCEL_BEGIN;
        // Converts the 2 strings.
        std::wstring str1 = xlStr1.AsWstring();
        std::wstring str2 = xlStr2.AsWstring();
        // Returns the concatenation of the 2 string as an XlfOper.
        std::wstring ret = str1+str2;
        return XlfOper(ret);
        EXCEL_END;
    }

    LPXLOPER EXCEL_EXPORT xlConcat4(XlfOper4 xlStr1, XlfOper4 xlStr2)
    {
        EXCEL_BEGIN;
        // Converts the 2 strings.
        std::string str1 = xlStr1.AsString();
        std::string str2 = xlStr2.AsString();
        // Returns the concatenation of the 2 string as an XlfOper.
        std::string ret = str1+str2;
        return XlfOper4(ret);
        EXCEL_END;
    }

    LPXLOPER12 EXCEL_EXPORT xlConcat12(XlfOper12 xlStr1, XlfOper12 xlStr2)
    {
        EXCEL_BEGIN;
        // Converts the 2 strings.
        std::wstring str1 = xlStr1.AsWstring();
        std::wstring str2 = xlStr2.AsWstring();
        // Returns the concatenation of the 2 string as an XlfOper.
        std::wstring ret = str1+str2;
        return XlfOper12(ret);
        EXCEL_END;
    }

    /*LPXLOPER*/ LPXLFOPER EXCEL_EXPORT xlStats(XlfOper xlTargetRange)
    {
        EXCEL_BEGIN;

        // Temporary variables.
        double averageTmp = 0.0;
        double varianceTmp = 0.0;

        // XlfExcel::Coerce method (internally called) will return to Excel
        // if one of the cell was invalidated and need to be recalculated.
        // Excel will calculate this cell and call again our function.
        // Thus we copy first all the data to avoid to partially compute the
        // average for nothing since one of the cell might be uncalculated.
        std::vector<double> temp = xlTargetRange.AsDoubleVector(XlfOperImpl::RowMajor);

        // All cells are copied. We do the actual work.
        size_t popSize = temp.size();
        for (size_t i = 0; i < popSize; ++i)
        {
            // sums the values.
            averageTmp += temp[i];
            // sums the squared values.
            varianceTmp += temp[i] * temp[i];
        }
        // Initialization of the resultArray.
        double resultArray[2];
        // compute average.
        double& average = resultArray[0];
        average = averageTmp / popSize;
        // compute variance
        double& variance = resultArray[1];
        variance = varianceTmp / popSize - average * average;
        // Create the XlfOper returned with the resultArray containing the values.
        return XlfOper(1,2,resultArray);

        EXCEL_END;
    }

    /*! 
     * Demonstrates how to detect that the function is called by
     * the function wizard, and how to retrieve the coordinates
     * of the caller cell
     */
    /*LPXLOPER*/ LPXLFOPER EXCEL_EXPORT xlIsInWiz()
    {
        EXCEL_BEGIN;

        // Checks if called from the function wizard
        if (XlfExcel::Instance().IsCalledByFuncWiz())
            return XlfOper(true);

        // Gets reference of the called cell
        XlfOper res;
        XlfExcel::Instance().Call(xlfCaller,res,0);
        XlfRef ref=res.AsRef();

        // Returns the reference in A1 format
        std::ostringstream ostr;
        char colChar='A'+ref.GetColBegin();
        ostr << colChar << ref.GetRowBegin() + 1 << std::ends;
        std::string address=ostr.str();

        return XlfOper(address.c_str());

        EXCEL_END;
    }

    /*!
     * Registered as volatile to demonstrate how functions can be 
     * recalculated automatically even if none of the arguments 
     * have changed.
     *
     * \return the number of times the function has been called.
     */
    /*LPXLOPER*/ LPXLFOPER EXCEL_EXPORT xlNbCalls()
    {
        EXCEL_BEGIN;

        static short nbCalls = 0;
        ++nbCalls;
        return XlfOper(nbCalls);

        EXCEL_END;
    }

    long EXCEL_EXPORT xlAutoOpen()
    {
        oldStreamBuf = std::cerr.rdbuf(&debuggerStreamBuf);
        std::cerr << XLW__HERE__ <<
            "std::cerr redirected to MSVC debugger" << std::endl;

        // Displays a message in the status bar.
        XlfExcel::Instance().SendMessage("Registering library...");

        // Registers the function xlCirc.
        // Variable description of type R (default).
        XlfArgDesc diameter("diameter", "Diameter of the circle");
        // xlCirc function description function as Circ.
        XlfFuncDesc circ("xlCirc", "Circ",
            "Computes the circumference of a circle", "xlw Example");
        // Set the diameter argument definition for circ.
        circ.SetArguments(diameter);
        // Registers the function circ.
        circ.Register();

        // Registers the function xlConcat.
        // Argument descriptions.
        XlfArgDesc concat_str1("string1", "First string");
        XlfArgDesc concat_str2("string2", "Second string");
        // xlConcat function description as concat.
        XlfFuncDesc concat("xlConcat", "Concat",
            "Concatenate two strings in one", "xlw Example");
        // Set the arguments for the function. Note how you create an
        // XlfArgDescList from two or more XlfArgDesc (operator+). You can not
        // push the XlfArgDesc one by one.
        concat.SetArguments(concat_str1+concat_str2);
        // Registers the concat function.
        concat.Register();

        // Registers the function xlConcat4.
        // Argument descriptions.
        XlfArgDesc concat4_str1("string1", "First string", "P");
        XlfArgDesc concat4_str2("string2", "Second string", "P");
        // xlConcat function description as concat.
        XlfFuncDesc concat4("xlConcat4", "Concat4",
            "Concatenate two strings in one", "xlw Example",
            XlfFuncDesc::NotVolatile, false, "P");
        // Set the arguments for the function. Note how you create an
        // XlfArgDescList from two or more XlfArgDesc (operator+). You can not
        // push the XlfArgDesc one by one.
        concat4.SetArguments(concat4_str1+concat4_str2);
        // Registers the concat function.
        concat4.Register();

        // Registers the function xlConcat12.
        // Argument descriptions.
        XlfArgDesc concat12_str1("string1", "First string", "Q");
        XlfArgDesc concat12_str2("string2", "Second string", "Q");
        // xlConcat function description as concat.
        XlfFuncDesc concat12("xlConcat12", "Concat12",
            "Concatenate two strings in one", "xlw Example",
            XlfFuncDesc::NotVolatile, false, "Q");
        // Set the arguments for the function. Note how you create an
        // XlfArgDescList from two or more XlfArgDesc (operator+). You can not
        // push the XlfArgDesc one by one.
        concat12.SetArguments(concat12_str1+concat12_str2);
        // Registers the concat function.
        concat12.Register();

        // Registers the function xlStats.
        // Argument descriptions.
        XlfArgDesc pop("Population", "Target range containing the population");
        // xlStats Function description
        XlfFuncDesc stats("xlStats", "Stats",
            "returns a (1x2) range containing the average and the variance "
            "of a numeric population", "xlw Example");
        // Sets the arguments for the function.
        stats.SetArguments(pop);
        // Registers the stats function.
        stats.Register();

        // Registers the function xlIsInWiz.
        XlfFuncDesc isInWiz("xlIsInWiz", "IsInWiz",
            "returns true if the function is called from the function wizard, "
            "and the address of the caller otherwise", "xlw Example");
        isInWiz.Register();

        // Registers the function xlNumberOfCall as volatile (unconditionally
        // recalculated)
        XlfFuncDesc nbCalls("xlNbCalls", "NbCalls",
            "returns the number of time the function has been calculated "
            "since the xll was loaded (volatile)", "xlw Example",
            XlfFuncDesc::Volatile);
        nbCalls.Register();

        // Clears the status bar.
        XlfExcel::Instance().SendMessage();
        return 1;
    }

    long EXCEL_EXPORT xlAutoClose()
    {
        std::cerr << XLW__HERE__ << "Releasing resources" << std::endl;
        delete &XlfExcel::Instance();
        std::cerr.rdbuf(oldStreamBuf);
        return 1;
    }

}


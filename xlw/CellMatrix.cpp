//
//
//						CellMatrix.cpp
//
//

#include "CellMatrix.h"
#include <algorithm>

bool CellValue::IsAString() const
{
	return Type == string;
}


bool CellValue::IsANumber() const
{
	return Type == number;
}

bool CellValue::IsBoolean() const
{
	return Type == boolean;
}

bool CellValue::IsError() const
{
	return Type == error;
}

bool CellValue::IsEmpty() const
{
	return Type == empty;
}


CellValue::operator std::string() const
{
	if (Type != string)
		throw("non string cell asked to be a string");
	return ValueAsString;

}
	
CellValue::operator bool() const
{
	if (Type != boolean)
		throw("non boolean cell asked to be a bool");
	return ValueAsBool;
}


CellValue::operator double() const
{
	if (Type != number)
		throw("non number cell asked to be a number");
	return ValueAsNumeric;


}

CellValue::operator unsigned long() const
{
	if (Type != number)
		throw("non number cell asked to be a number");
	return static_cast<unsigned long>(ValueAsNumeric);

}

void CellValue::clear()
{
	Type = empty;
	ValueAsString="";
	ValueAsNumeric=0.0;
	ValueAsBool=false;
	ValueAsErrorCode=0;
}


CellValue::CellValue(const std::string& value) : Type(CellValue::string), 
ValueAsString(value), ValueAsNumeric(0.0), ValueAsBool(false), ValueAsErrorCode(0)
{

}


CellValue::CellValue(const char* value) : Type(CellValue::string), 
ValueAsString(value), ValueAsNumeric(0.0), ValueAsBool(false), ValueAsErrorCode(0)
{

}
CellValue::CellValue(double Number): Type(CellValue::number), 
ValueAsString(""), ValueAsNumeric(Number), ValueAsBool(false), ValueAsErrorCode(0)
{

}
CellValue::CellValue(unsigned long Code, bool Error): Type(error), 
ValueAsString(""), ValueAsNumeric(Code), ValueAsBool(false), ValueAsErrorCode(Code)
{
	if (!Error)
		Type = number;
}

CellValue::CellValue(bool TrueFalse)
 : Type(CellValue::boolean), 
ValueAsString(""), ValueAsNumeric(0.0), ValueAsBool(TrueFalse), ValueAsErrorCode(0)
{

}

CellValue::CellValue(): Type(CellValue::empty), 
ValueAsString(""), ValueAsNumeric(0.0), ValueAsBool(false), ValueAsErrorCode(0)
{
}

const std::string& CellValue::StringValue() const
{
	if (Type != string)
		throw("non string cell asked to be a string");
	return ValueAsString;
}
double CellValue::NumericValue() const
{
	
	if (Type != number)
		throw("non number cell asked to be a number");
	return ValueAsNumeric;
}
bool CellValue::BooleanValue() const
{
	
	if (Type != boolean)
		throw("non boolean cell asked to be a bool");

	return ValueAsBool;
}
unsigned long CellValue::ErrorValue() const
{
	if (Type != error)
		throw("non error cell asked to be an error");

	return ValueAsErrorCode;
}

std::string CellValue::StringValueLowerCase() const
{
	if (Type != string)
		throw("non string cell asked to be a string");
	std::string tmp(ValueAsString);

    std::transform(tmp.begin(),tmp.end(),tmp.begin(),tolower);
	return tmp;
}


CellMatrix::CellMatrix(unsigned long rows, unsigned long columns) : Cells(rows), Rows(rows), Columns(columns)
{
	for (unsigned long i=0; i < rows; i++)
		Cells[i].resize(columns);
}
    
const CellValue& CellMatrix::operator()(unsigned long i, unsigned long j) const
{
	return Cells.at(i).at(j);

}
CellValue& CellMatrix::operator()(unsigned long i, unsigned long j)
{
	return Cells.at(i).at(j);
}

unsigned long CellMatrix::RowsInStructure() const
{
	return Rows;
}
unsigned long CellMatrix::ColumnsInStructure() const
{	
	return Columns;
}

CellMatrix MergeCellMatrices(const CellMatrix& Top, const CellMatrix& Bottom)
{
	unsigned long cols = std::max(Top.ColumnsInStructure(), Bottom.ColumnsInStructure());
	unsigned long rows = Top.RowsInStructure()+Bottom.RowsInStructure();

	CellMatrix merged(rows,cols);

	for (unsigned long i=0; i < Top.ColumnsInStructure(); i++)
		for (unsigned long j=0; j < Top.RowsInStructure(); j++)
			merged(j,i) = Top(j,i);

	for (unsigned long i=0; i < Bottom.ColumnsInStructure(); i++)
		for (unsigned long j=0; j < Bottom.RowsInStructure(); j++)
			merged(j+Top.RowsInStructure(),i) = Bottom(j,i);


	return merged;
}

void CellMatrix::PushBottom(const CellMatrix& newRows)
{
	CellMatrix newRowsResize(newRows);
	unsigned long newColumns = std::max(newRows.ColumnsInStructure(),Columns);

	if (newColumns > Columns)
		for (unsigned long i=0; i < Rows; i++)
			Cells[i].resize(newColumns);

	if (newColumns > newRows.Columns)
		for (unsigned long i=0; i < newRowsResize.Rows; i++)
			newRowsResize.Cells[i].resize(newColumns);

	for (unsigned long i=0; i < newRowsResize.Rows; i++)
		Cells.push_back(newRowsResize.Cells[i]);

	Rows = static_cast<unsigned long>(Cells.size());
	Columns = newColumns;

	

}

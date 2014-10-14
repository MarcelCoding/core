#include "precompiled_xls.h"
#include "MSOSHADECOLOR.h"
#include <Binary/CFRecord.h>

namespace ODRAW
{;

MSOSHADECOLOR::MSOSHADECOLOR()
{
}

XLS::BiffStructurePtr MSOSHADECOLOR::clone()
{
	return XLS::BiffStructurePtr(new MSOSHADECOLOR(*this));
}

//
//void MSOSHADECOLOR::setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag)
//{
//	color.toXML(xml_tag);
//	position.toXML(xml_tag, L"position");
//}
//
//void MSOSHADECOLOR::getXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag)
//{
//	// We don't support xlsx to xls conversion
//}


void MSOSHADECOLOR::store(XLS::CFRecord& record)
{
	// We don't support xlsx to xls conversion
}


void MSOSHADECOLOR::load(XLS::CFRecord& record)
{
	long raw_color;
	record >> raw_color >> position;
	color = OfficeArtCOLORREF(raw_color);
}


} // namespace XLS
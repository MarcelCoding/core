#include "precompiled_cpodf.h"
#include "draw_shapes.h"
#include "custom_shape_types_convert.h"

#include <ostream>
#include <sstream>
#include <string>

#include <boost/foreach.hpp>
#include <boost_string.h>
#include <regex.h>

#include <cpdoccore/xml/xmlchar.h>
#include <cpdoccore/xml/serialize.h>
#include <cpdoccore/xml/attributes.h>

#include "style_graphic_properties.h"
#include "length.h"
#include "borderstyle.h"

#include "odf_conversion_context.h"

#include "svg_creator.h"

namespace cpdoccore { 
namespace odf {

using xml::xml_char_wc;


const wchar_t * draw_shape::ns = L"draw";
const wchar_t * draw_shape::name = L"shape";
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_shape::serialize(std::wostream & _Wostream)
{
	draw_base::serialize(_Wostream);
}
void draw_shape::serialize_attlist(CP_ATTR_NODE)
{
	draw_base::serialize_attlist(CP_GET_XML_NODE());
	common_xlink_attlist_.serialize(CP_GET_XML_NODE());
	
	CP_XML_ATTR_OPT(L"draw:id", draw_id_);
}

void draw_rect_attlist::serialize(CP_ATTR_NODE)
{
    CP_XML_ATTR_OPT(L"draw:filter-name", draw_filter_name_);
}

const wchar_t * draw_rect::ns = L"draw";
const wchar_t * draw_rect::name = L"rect";

void draw_rect::serialize(std::wostream & _Wostream)
{
	sub_type_ = 2;//todooo ����������
	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
	
			draw_rect_attlist_.serialize(CP_GET_XML_NODE());

			draw_shape::serialize(CP_XML_STREAM());
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// draw-ellipse-attlist

void draw_ellipse_attlist::serialize(CP_ATTR_NODE)
{
    CP_XML_ATTR_OPT(L"draw:filter-name", draw_filter_name_);
}

/// draw:ellipse
const wchar_t * draw_ellipse::ns = L"draw";
const wchar_t * draw_ellipse::name = L"ellipse";


void draw_ellipse::serialize(std::wostream & _Wostream)
{
	sub_type_ = 3;
	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
	
			draw_ellipse_attlist_.serialize(CP_GET_XML_NODE());

			draw_shape::serialize(CP_XML_STREAM());
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// draw:circle
const wchar_t * draw_circle::ns = L"draw";
const wchar_t * draw_circle::name = L"circle";

void draw_circle::serialize(std::wostream & _Wostream)
{
	sub_type_ = 4;
	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
	
			draw_shape::serialize(CP_XML_STREAM());
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// draw-line-attlist
void draw_line_attlist::serialize(CP_ATTR_NODE)
{
    CP_XML_ATTR_OPT(L"svg:x1", svg_x1_);
    CP_XML_ATTR_OPT(L"svg:x2", svg_x2_);
    CP_XML_ATTR_OPT(L"svg:y1", svg_y1_);
    CP_XML_ATTR_OPT(L"svg:y2", svg_y2_);
}
// draw:line
const wchar_t * draw_line::ns = L"draw";
const wchar_t * draw_line::name = L"line";

void draw_line::serialize(std::wostream & _Wostream)
{
	sub_type_ = 5;
	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
	
			draw_line_attlist_.serialize(CP_GET_XML_NODE());

			draw_shape::serialize(CP_XML_STREAM());
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
// draw:custom_shape
const wchar_t * draw_custom_shape::ns = L"draw";
const wchar_t * draw_custom_shape::name = L"custom-shape";

void draw_custom_shape::serialize(std::wostream & _Wostream)
{
	sub_type_ = 7;
	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
	
			draw_shape::serialize(CP_XML_STREAM());
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
/// draw-path-attlist
void draw_path_attlist::serialize(CP_ATTR_NODE)
{
    CP_XML_ATTR_OPT(L"svg:d", svg_d_);
    CP_XML_ATTR_OPT(L"svg:viewBox", svg_viewbox_);

}
// draw:path
const wchar_t * draw_path::ns = L"draw";
const wchar_t * draw_path::name = L"path";

void draw_path::serialize(std::wostream & _Wostream)
{
	sub_type_ = 6;
	reset_svg_path();

	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
	
			draw_path_attlist_.serialize(CP_GET_XML_NODE());

			draw_shape::serialize(CP_XML_STREAM());
		}
	}	
}
void draw_path::reset_svg_path()//todooo ��������
{
	//if (draw_path_attlist_.svg_d_)
	//{
	//	std::vector<svg_path::_polyline> o_Polyline_pt;
	//	std::vector<svg_path::_polyline> o_Polyline_cm;
	//
	//	bool res = svg_path::createSvgD(o_Polyline_cm,draw_path_attlist_.svg_d_.get(),false);
	//	
	//	BOOST_FOREACH(svg_path::_polyline  & poly, o_Polyline_cm)
	//	{
	//		for (long i=0;i<poly.points.size();i++)
	//		{
	//			if (poly.points[i].x)
	//			{
	//				poly.points[i].x =  length(poly.points[i].x.get()/1000.,length::cm).get_value_unit(length::emu); 
	//			}
	//			if (poly.points[i].y)
	//			{
	//				poly.points[i].y = length(poly.points[i].y.get()/1000.,length::cm).get_value_unit(length::emu); 
	//			}
	//		}
	//		o_Polyline_pt.push_back(poly);
	//	}
	//	if (o_Polyline_pt.size()>0)
	//	{
	//		//���������� xml-oox ����� ... � �� �������� ������� ������� � drawing .. ���� � �� �������..
	//		std::wstringstream output_;   
	//		//svg_path::oox_serialize(output_, o_Polyline_pt);
	//		additional_.push_back(odf::_property(L"custom_path",output_.str()));
	//	}
	//}
}
///////////////////////////////////////
void draw_polygon_attlist::serialize(CP_ATTR_NODE)
{
    CP_XML_ATTR_OPT(L"draw:points", draw_points_);
    CP_XML_ATTR_OPT(L"svg:viewBox", svg_viewbox_);

}
// draw:polygon
const wchar_t * draw_polygon::ns = L"draw";
const wchar_t * draw_polygon::name = L"polygon";

void draw_polygon::serialize(std::wostream & _Wostream)
{
	sub_type_ = 8;
	reset_polygon_path();

	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
	
			draw_polygon_attlist_.serialize(CP_GET_XML_NODE());

			draw_shape::serialize(CP_XML_STREAM());
		}
	}	
}
void draw_polygon::reset_polygon_path()
{
	//if (draw_polygon_attlist_.draw_points_)
	//{
	//	std::vector<svg_path::_polyline> o_Polyline_pt;
	//	std::vector<svg_path::_polyline> o_Polyline_cm;

	//	bool res = svg_path::createPolygon(o_Polyline_cm,draw_polygon_attlist_.draw_points_.get(),false);
	//	
	//	BOOST_FOREACH(svg_path::_polyline  & poly, o_Polyline_cm)
	//	{
	//		for (long i=0;i<poly.points.size();i++)
	//		{
	//			if (poly.points[i].x)
	//			{
	//				poly.points[i].x =  length(poly.points[i].x.get()/1000.,length::cm).get_value_unit(length::emu); 
	//			}
	//			if (poly.points[i].y)
	//			{
	//				poly.points[i].y = length(poly.points[i].y.get()/1000.,length::cm).get_value_unit(length::emu); 
	//			}
	//		}
	//		o_Polyline_pt.push_back(poly);
	//	}
	//	if (o_Polyline_pt.size()>0)
	//	{
	//		//���������� xml-oox ����� ... � �� �������� ������� ������� � drawing .. ���� � �� �������..
	//		std::wstringstream output_;   
	//		svg_path::oox_serialize(output_, o_Polyline_pt);
	//		additional_.push_back(odf::_property(L"custom_path",output_.str()));
	//	}
	//}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void draw_equation_attlist::serialize(CP_ATTR_NODE)
{	
	CP_XML_ATTR_OPT(L"draw:name", draw_name_);
	CP_XML_ATTR_OPT(L"draw:formula", draw_formula_);
}
void draw_handle_attlist::serialize(CP_ATTR_NODE)
{	
	CP_XML_ATTR_OPT(L"draw:handle-position", draw_handle_position_);

	CP_XML_ATTR_OPT(L"draw:handle-range-y-maximum", draw_handle_range_y_maximum_);
	CP_XML_ATTR_OPT(L"draw:handle-range-y-minimum", draw_handle_range_y_minimum_);

	CP_XML_ATTR_OPT(L"draw:handle-range-x-maximum", draw_handle_range_x_maximum_);
	CP_XML_ATTR_OPT(L"draw:handle-range-x-minimum", draw_handle_range_x_minimum_);
	
	CP_XML_ATTR_OPT(L"draw:handle-radius-range-maximum", draw_handle_radius_range_maximum_);
	CP_XML_ATTR_OPT(L"draw:handle-radius-range-minimum", draw_handle_radius_range_minimum_);
	
	CP_XML_ATTR_OPT(L"draw:handle-polar", draw_handle_polar_);
}
// draw:path
const wchar_t * draw_handle::ns = L"draw";
const wchar_t * draw_handle::name = L"handle";

void draw_handle::serialize(std::wostream & _Wostream)
{
  	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_handle_attlist_.serialize(CP_GET_XML_NODE());
		}
	}
}
const wchar_t * draw_equation::ns = L"draw";
const wchar_t * draw_equation::name = L"equation";

void draw_equation::serialize(std::wostream & _Wostream)
{
	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_equation_attlist_.serialize(CP_GET_XML_NODE());
		}
	}	
}
int draw_enhanced_geometry::parsing(_CP_OPT(std::wstring) val) 
{
	int pos=0, res=-1;
	if (!val)return res;

	BOOST_FOREACH(wchar_t c, val.get())
    {
		if (c < L'0' && c > L'9')
			return res;
	}

	if ((pos = val->find(L"$"))>=0)return res;
	res = boost::lexical_cast<int>(val.get());
	return res;
}


/// draw-enhanced_geometry_attlist
void draw_enhanced_geometry_attlist::serialize(CP_ATTR_NODE)
{
    CP_XML_ATTR_OPT(L"draw:type", draw_type_);
    CP_XML_ATTR_OPT(L"draw:text-areas", draw_text_areas_);
    CP_XML_ATTR_OPT(L"draw:modifiers", draw_modifiers_);
    CP_XML_ATTR_OPT(L"draw:enhanced-path", draw_enhanced_path_);	
	CP_XML_ATTR_OPT(L"draw:glue-points", draw_glue_points_);
}
// draw:enhanced_geometry
const wchar_t * draw_enhanced_geometry::ns = L"draw";
const wchar_t * draw_enhanced_geometry::name = L"enhanced-geometry";

void draw_enhanced_geometry::serialize(std::wostream & _Wostream)
{
	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			CP_XML_ATTR_OPT(L"svg:viewBox", svg_viewbox_);
			draw_enhanced_geometry_attlist_.serialize(CP_GET_XML_NODE());
			
			BOOST_FOREACH(office_element_ptr & elm, draw_equation_)
			{
				elm->serialize(CP_XML_STREAM());
			}		
			
			BOOST_FOREACH(office_element_ptr & elm, draw_handle_)
			{
				elm->serialize(CP_XML_STREAM());
			}

		}
	}
}

typedef shared_ptr<draw_handle> draw_handle_ptr;

void draw_enhanced_geometry::create_child_element( const ::std::wstring & Ns, const ::std::wstring & Name)
{
    if CP_CHECK_NAME(L"draw", L"handle")
    {
        CP_CREATE_ELEMENT(draw_handle_);
	}
	else if CP_CHECK_NAME(L"draw", L"equation")
	{
		CP_CREATE_ELEMENT(draw_equation_);
	}
    else
    {
        //not_applicable_element(L"draw_enhanced_geometry", Reader, Ns, Name);
    }

}
void draw_enhanced_geometry::add_child_element(office_element_ptr & child_element)
{
 	ElementType type = child_element->get_type();

    if (type == typeDrawHandle)
	{
		draw_handle_.push_back(child_element);
	}
	else if (type == typeDrawEquation)
	{
		draw_equation_.push_back(child_element);
	}
    else
    {
        //not_applicable_element(L"draw_enhanced_geometry", Reader, Ns, Name);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////
// draw:caption
//////////////////////////////////////////////////////////////////////////////////////////////////
const wchar_t * draw_caption::ns = L"draw";
const wchar_t * draw_caption::name = L"caption";

void draw_caption::serialize(std::wostream & _Wostream)
{
	sub_type_ = 1;	

	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
	
			draw_shape::serialize(CP_XML_STREAM());
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
/// draw-connector-attlist
void draw_connector_attlist::serialize(CP_ATTR_NODE)
{
    CP_XML_ATTR_OPT(L"svg:d", svg_d_);
    CP_XML_ATTR_OPT(L"svg:viewBox", svg_viewbox_);
    CP_XML_ATTR_OPT(L"draw:type",draw_type_);

}
// draw:connector
const wchar_t * draw_connector::ns = L"draw";
const wchar_t * draw_connector::name = L"connector";

void draw_connector::serialize(std::wostream & _Wostream)
{
	sub_type_ = 5; //��������� - �����, ���� ������� (���� ������������) - �� ����

	reset_svg_path();

	CP_XML_WRITER(_Wostream)
    {
		CP_XML_NODE_SIMPLE()
        {
			draw_shape::serialize_attlist(CP_GET_XML_NODE());
			
			draw_connector_attlist_.serialize(CP_GET_XML_NODE());
			draw_line_attlist_.serialize(CP_GET_XML_NODE());
	
			draw_shape::serialize(CP_XML_STREAM());
		}
	}	
}
void draw_connector::reset_svg_path()
{
	//if (draw_connector_attlist_.svg_d_)
	//{
	//	std::vector<svg_path::_polyline> o_Polyline_pt;
	//	std::vector<svg_path::_polyline> o_Polyline_cm;
	//
	//	bool res = svg_path::createSvgD(o_Polyline_cm,draw_connector_attlist_.svg_d_.get(),false);
	//
	//	double x1=common_draw_attlists_.position_.svg_x_.get_value_or(length(0)).get_value_unit(length::emu);
	//	double y1=common_draw_attlists_.position_.svg_y_.get_value_or(length(0)).get_value_unit(length::emu);
	//	
	//	BOOST_FOREACH(svg_path::_polyline  & poly, o_Polyline_cm)
	//	{
	//		for (long i=0;i<poly.points.size();i++)
	//		{
	//			if (poly.points[i].x)
	//			{
	//				poly.points[i].x =  length(poly.points[i].x.get()/1000.,length::cm).get_value_unit(length::emu)-x1; 
	//			}
	//			if (poly.points[i].y)
	//			{
	//				poly.points[i].y = length(poly.points[i].y.get()/1000.,length::cm).get_value_unit(length::emu)-y1; 
	//			}
	//		}
	//		o_Polyline_pt.push_back(poly);
	//	}
	//	if (o_Polyline_pt.size()>0)
	//	{
	//		sub_type_ = 6;
	//		//���������� xml-oox ����� ... � �� �������� ������� ������� � drawing .. ���� � �� �������..
	//		std::wstringstream output_;   
	//		svg_path::oox_serialize(output_, o_Polyline_pt);
	//		additional_.push_back(odf::_property(L"custom_path",output_.str()));
	//	}
	//}
}
///////////////////////////////////////

}
}
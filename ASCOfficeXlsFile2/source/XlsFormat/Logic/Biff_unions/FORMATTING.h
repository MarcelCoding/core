#pragma once

#include <Logic/CompositeObject.h>

namespace XLS
{


// Logical representation of FORMATTING union of records 
class FORMATTING: public CompositeObject
{
	BASE_OBJECT_DEFINE_CLASS_NAME(FORMATTING)
public:
	FORMATTING();
	~FORMATTING();

	BaseObjectPtr clone();

	virtual const bool loadContent(BinProcessor& proc);

	int serialize1(std::wostream & stream);
	int serialize2(std::wostream & stream);

	static const ElementType	type = typeFORMATTING;

	BaseObjectPtr				m_Styles;
	BaseObjectPtr				m_XFS;
	std::vector<BaseObjectPtr>	m_arFormats;
	std::vector<BaseObjectPtr>	m_arFonts;
	BaseObjectPtr				m_Palette;
	BaseObjectPtr				m_ClrtClient;
	std::vector<BaseObjectPtr>	m_arDXF;


	GlobalWorkbookInfoPtr		global_info;
};

} // namespace XLS


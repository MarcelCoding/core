#ifndef CCSSCALCULATOR_PRIVATE_H
#define CCSSCALCULATOR_PRIVATE_H

#include <vector>
#include <map>
#include <list>
#include <functional>
#include "CElement.h"
#include "ConstValues.h"
#include "CUnitMeasureConverter.h"
#include "../../katana-parser/src/katana.h"

#ifdef CSS_CALCULATOR_WITH_XHTML
#include "CCompiledStyle.h"
#endif

namespace NSCSS
{
	class CCssCalculator_Private
	{
		unsigned short int m_nDpi;
		unsigned short int m_nCountNodes;
		UnitMeasure m_UnitMeasure;

		std::list<std::wstring> m_arFiles;

		std::map<std::wstring, CElement*> m_mData;

		std::map<StatistickElement, unsigned int> *m_mStatictics; // Количество повторений свойств id и style у селекторов

		#ifdef CSS_CALCULATOR_WITH_XHTML
		std::map<std::vector<CNode>, CCompiledStyle*> m_mUsedStyles;
		#endif

		std::wstring m_sEncoding;

		CSizeWindow m_oSourceWindow;
		CSizeWindow m_oDeviceWindow;

		void GetStylesheet(const KatanaStylesheet* oStylesheet);
		void GetRule(const KatanaRule* oRule);

		void GetStyleRule(const KatanaStyleRule* oRule);

		std::wstring GetValueList(const KatanaArray* oValues);

		std::vector<std::wstring> GetSelectorList(const KatanaArray* oSelectors) const;
		std::wstring GetSelector(const KatanaSelector* oSelector) const;

		std::map<std::wstring, std::wstring> GetDeclarationList(const KatanaArray* oDeclarations) const;
		std::pair<std::wstring, std::wstring> GetDeclaration(const KatanaDeclaration* oDecl) const;

		void GetOutputData(KatanaOutput* oOutput);

	public:
		CCssCalculator_Private();
		~CCssCalculator_Private();

		#ifdef CSS_CALCULATOR_WITH_XHTML
		CCompiledStyle GetCompiledStyle(const std::vector<CNode> &arSelectors, const bool& bIsSettings = false, const UnitMeasure& unitMeasure = Point);
		bool GetCompiledStyle(CCompiledStyle& oStyle, const std::vector<CNode> &arSelectors, const bool& bIsSettings = false, const UnitMeasure& unitMeasure = Point);
		#endif

		void AddStyles(const std::string& sStyle);
		void AddStyles(const std::wstring& wsStyle);
		void AddStylesFromFile(const std::wstring& wsFileName);

		void SetUnitMeasure(const UnitMeasure& nType);
		void SetDpi(unsigned short int nValue);
		void SetBodyTree(const CTree &oTree);

		void SetSizeSourceWindow(const CSizeWindow& oSizeWindow);
		void SetSizeDeviceWindow(const CSizeWindow& oSizeWindow);

		CSizeWindow GetSizeSourceWindow() const;
		CSizeWindow GetSizeDeviceWindow() const;

		UnitMeasure GetUnitMeasure() const;
		std::wstring GetEncoding() const;
		unsigned short int GetDpi() const;

		const std::map<std::wstring, CElement*>* GetData() const;

		void Clear();

	};
}
#endif // CCSSCALCULATOR_PRIVATE_H

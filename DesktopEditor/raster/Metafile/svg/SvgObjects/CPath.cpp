#include "CPath.h"

#include <algorithm>

namespace SVG
{
	CPath::CPath(CObjectBase *pParent)
	{

	}

	CPath::~CPath()
	{
		for (IPathElement* pPathElement : m_arElements)
			delete pPathElement;
	}

	bool CPath::ReadFromXmlNode(XmlUtils::CXmlNode &oNode)
	{
		std::wstring wsPoints = oNode.GetAttribute(L"d");

		if (wsPoints.empty())
			return false;

		ReadFromString(wsPoints);

		UpdateStyle(oNode);

		return true;
	}

	bool CPath::Draw(IRenderer *pRenderer)
	{
		if (NULL == pRenderer || m_arElements.empty())
			return false;

		ApplyStyle(pRenderer);

		pRenderer->PathCommandStart();
		pRenderer->BeginCommand ( c_nPathType );

		for (IPathElement* oElement : m_arElements)
			oElement->Draw(pRenderer);

		pRenderer->DrawPath (/*c_nWindingFillMode | */c_nStroke);
		pRenderer->EndCommand (c_nPathType);
		pRenderer->PathCommandEnd();

		return true;
	}

	void CPath::ApplyStyle(IRenderer *pRenderer)
	{
		if (NULL == pRenderer)
			return;

		pRenderer->put_BrushColor1(m_oStyle.GetFillL());
//		pRenderer->put_PenColor(m_oStyle.GetStrokeColor());
	}

	void CPath::ReadFromString(const std::wstring &wsValue)
	{
		std::wstring::const_iterator oFirstPos = wsValue.begin();
		std::wstring::const_iterator oSecondPos = oFirstPos;

		IPathElement *pLastElement = NULL;
		IPathElement *pMoveElement = NULL;

		while (true)
		{
			oFirstPos = std::find_if(oSecondPos, wsValue.end(), iswalpha );

			if (wsValue.end() == oFirstPos)
				break;

			oSecondPos = std::find_if(oFirstPos + 1, wsValue.end(), iswalpha );

			switch(*oFirstPos)
			{
				case L'M':
				case L'm':
				{
					IPathElement *pElement = new CMoveElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;
					pMoveElement = pElement;

					break;
				}
				case L'L':
				case L'l':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CLineElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;

					break;
				}
				case L'H':
				case L'h':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CHLineElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;

					break;
				}
				case L'V':
				case L'v':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CVLineElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;

					break;
				}
				case L'C':
				case L'c':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CCBezierElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;

					break;
				}
				case L'S':
				case L's':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CSBezierElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;

					break;
				}
				case L'Q':
				case L'q':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CQBezierElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;

					break;
				}
				case L'T':
				case L't':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CTBezierElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;

					break;
				}
				case L'A':
				case L'a':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CArcElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pLastElement);

					m_arElements.push_back(pElement);

					pLastElement = pElement;

					break;
				}
				case L'Z':
				case L'z':
				{
					if (NULL == pMoveElement)
						return;

					IPathElement *pElement = new CCloseElement();
					pElement->ReadFromString(std::wstring(oFirstPos + 1, oSecondPos), iswlower(*oFirstPos), pMoveElement);

					m_arElements.push_back(pElement);

					pLastElement = pMoveElement;

					break;
				}
			}

			oFirstPos = oSecondPos;
		}
	}

}


// Mid3View.h: CMid3View 클래스의 인터페이스
//

#pragma once


class CMid3View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMid3View() noexcept;
	DECLARE_DYNCREATE(CMid3View)

// 특성입니다.
public:
	CMid3Doc* GetDocument() const;

// 작업입니다.
public:
	CPoint pnt;
	COLORREF Col;
	int Size;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMid3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	afx_msg void OnMenuCol();
	afx_msg void OnSize1();
	afx_msg void OnSize8();
	afx_msg void OnSize16();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

#ifndef _DEBUG  // Mid3View.cpp의 디버그 버전
inline CMid3Doc* CMid3View::GetDocument() const
   { return reinterpret_cast<CMid3Doc*>(m_pDocument); }
#endif


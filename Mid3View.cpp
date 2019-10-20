
// Mid3View.cpp: CMid3View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Mid3.h"
#endif

#include "Mid3Doc.h"
#include "Mid3View.h"
#include "CLine.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMid3View

IMPLEMENT_DYNCREATE(CMid3View, CView)

BEGIN_MESSAGE_MAP(CMid3View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENU_COL, &CMid3View::OnMenuCol)
	ON_COMMAND(ID_SIZE_1, &CMid3View::OnSize1)
	ON_COMMAND(ID_SIZE_8, &CMid3View::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CMid3View::OnSize16)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// CMid3View 생성/소멸

CMid3View::CMid3View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMid3View::~CMid3View()
{
}

BOOL CMid3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMid3View 그리기

void CMid3View::OnDraw(CDC* pDC)
{
	CMid3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n = pDoc->m_oa.GetSize();
	for (int i = 0; i < n; i++) {
		CLine* p;
		p = (CLine*)pDoc->m_oa[i];
		p->Draw(pDC);
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMid3View 인쇄

BOOL CMid3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMid3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMid3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMid3View 진단

#ifdef _DEBUG
void CMid3View::AssertValid() const
{
	CView::AssertValid();
}

void CMid3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMid3Doc* CMid3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMid3Doc)));
	return (CMid3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMid3View 메시지 처리기


void CMid3View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags == MK_LBUTTON) {
		CLine* p = new CLine(pnt, point, Size, Col);
		GetDocument()->m_oa.Add(p);
		Invalidate(FALSE);
	}
	pnt = point;
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMouseMove(nFlags, point);
}


void CMid3View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	Col = RGB(0, 255, 0);
	Size = 2;


	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CMid3View::OnMenuCol()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Col = dlg.GetColor();
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMid3View::OnSize1()
{
	Size = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMid3View::OnSize8()
{
	Size = 8;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMid3View::OnSize16()
{
	Size = 16;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMid3View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)

{
	CMenu m;
	m.LoadMenu(IDR_MAINFRAME);
	CMenu* p = m.GetSubMenu(0);
	p->TrackPopupMenu(NULL, point.x, point.y, this, NULL);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

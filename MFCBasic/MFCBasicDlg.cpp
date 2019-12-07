
// MFCBasicDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCBasic.h"
#include "MFCBasicDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCBasicDlg dialog



CMFCBasicDlg::CMFCBasicDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCBASIC_DIALOG, pParent)
	, CheckMale(0)
	, CheckFeMale(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCBasicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOXName, ComboBoxName);
	DDX_Control(pDX, IDC_CHECKEnglish, CheckEnglish);
	DDX_Control(pDX, IDC_CHECKFrance, CheckFrance);
	DDX_Control(pDX, IDC_CHECKChina, CheckChina);
	DDX_Control(pDX, IDC_EDITAddress, CeditAddress);
	DDX_Check(pDX, IDC_RADIOMale, CheckMale);
	DDX_Check(pDX, IDC_RADIOFemale, CheckFeMale);
}

BEGIN_MESSAGE_MAP(CMFCBasicDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCBasicDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCBasicDlg message handlers

BOOL CMFCBasicDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	CheckMale = 1;
	UpdateData(false);
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCBasicDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCBasicDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString CMFCBasicDlg::GetNameValuesComBoBox()
{
	CString ten = _T("");
	ComboBoxName.GetWindowText(ten);
	if (ten.GetLength() == 0) {
		MessageBox(_T("Chưa nhập tên"), _T("Cảnh báo"), MB_ICONINFORMATION);
		ComboBoxName.SetWindowText(_T("Chua nhap ten"));
	}
	return ten;
}

CString CMFCBasicDlg::GetSex() {
	CString gioiTinh = _T("");
	if (CheckMale == 1) {
		return _T("nam");
	}
	else
	{
		CheckFeMale = 1;
		UpdateData(true);
		return _T("nữ");
	}

}

CString CMFCBasicDlg::GetAddress() {
	CString address = _T("");
	CeditAddress.GetWindowTextW(address);
	if (address.GetLength() == 0) {
		MessageBox(_T("Chưa nhập địa chỉ"), _T("Cảnh báo"), MB_ICONINFORMATION);
		CeditAddress.SetWindowText(_T("Chua nhập địa chỉ"));
	}
	return address;
}
CString CMFCBasicDlg::GetLanguage() {
	CString language = _T("");
	CString s = _T("");
	if (CheckEnglish.GetCheck())
		CheckEnglish.GetWindowTextW(language);
	if (CheckFrance.GetCheck() == 1)
	{	
		
		CheckFrance.GetWindowTextW(s);
		language += _T(";") + s;
	}
	if (CheckChina.GetCheck() == 1) {
		CheckChina.GetWindowTextW(language);
		language += _T(";") + s;
	}
	return language;
}

void CMFCBasicDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString name = GetNameValuesComBoBox();
	CString sex = GetSex();
	CString address = GetAddress();
	CString language = GetLanguage();
	MessageBox(_T("tên: ") + name + _T("\nGiới tính: ") + sex + _T("\nĐịa chỉ: ") + _T("\n ngon ngu: ") + GetLanguage(), _T("thong báo"), MB_ICONINFORMATION);

	//CDialogEx::OnOK();
}

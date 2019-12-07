
// MFCBasicDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFCBasicDlg dialog
class CMFCBasicDlg : public CDialogEx
{
// Construction
public:
	CMFCBasicDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBASIC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	CString GetNameValuesComBoBox();
	CString GetSex();
	CString GetAddress();
	CString GetLanguage();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
protected:
	
public:
	CEdit CeditAddress;
	int CheckMale;
	int CheckFeMale;
	CButton CheckEnglish;
	CButton CheckFrance;
	CButton CheckChina;
	CComboBox ComboBoxName;
};


// CLIENTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CLIENT.h"
#include "CLIENTDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCLIENTDlg dialog

CCLIENTDlg::CCLIENTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCLIENTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCLIENTDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btn_browse, &CCLIENTDlg::OnBnClickedbrowse)
	ON_BN_CLICKED(btn_search, &CCLIENTDlg::OnBnClickedsearch)
	ON_BN_CLICKED(btn_forward, &CCLIENTDlg::OnBnClickedforward)
END_MESSAGE_MAP()


// CCLIENTDlg message handlers

BOOL CCLIENTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCLIENTDlg::OnPaint()
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
HCURSOR CCLIENTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Click on btn_browse
void CCLIENTDlg::OnBnClickedbrowse()
{
	CFileDialog l_fDlg(TRUE);
	int iRet = l_fDlg.DoModal();
	CString l_strFileName;
	l_strFileName = l_fDlg.GetPathName();

	if (iRet == IDOK) {
		try
		{
			CStdioFile file(l_strFileName, CFile::modeRead);
			CString str, contentstr = _T("");

			while (file.ReadString(str))
			{
				contentstr += str;
				contentstr += _T("\n");
			}
			CString cPathToFile = l_fDlg.GetPathName();
			SetDlgItemText(edit_file, cPathToFile);
			pathToFile = CW2A(cPathToFile.GetString());
		}
		catch (CException* e)
		{
			MessageBox(_T("Error"));
			e->Delete();
		}
	}
}

void CCLIENTDlg::OnBnClickedsearch()
{
	string temp = "abc" + pathToFile;
	CString aaa(temp.c_str(), temp.length());
	SetDlgItemText(edit_file, aaa);
}


void CCLIENTDlg::OnBnClickedforward()
{

}

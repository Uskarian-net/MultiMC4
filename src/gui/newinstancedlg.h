#pragma once

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <vector>

class ShadedTextEdit;
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class NewInstanceDialog
///////////////////////////////////////////////////////////////////////////////
class NewInstanceDialog : public wxDialog 
{
	protected:
		class MCVersionChoice : public wxChoice
		{
		public:
			MCVersionChoice(NewInstanceDialog* parent, wxWindowID id = wxID_ANY) :wxChoice(parent, id)
			{
				m_owner = parent;
			};
			
			//virtual unsigned int GetCount() const;
			//virtual wxString GetString ( unsigned int n ) const;
			
			void Refilter();
			
		protected:
			std::vector<unsigned> visibleIndexes;
			NewInstanceDialog* m_owner;
			//DECLARE_EVENT_TABLE()
		};
	
	protected:
		wxButton* m_btnIcon;
		ShadedTextEdit* m_textName;
		wxTextCtrl* m_textFolder;
		MCVersionChoice* m_choiceMCVersion;
		wxCheckBox* m_checkOldSnapshots;
		wxCheckBox* m_checkNewSnapshots;
		wxChoice* m_choiceLwjgl;
		wxButton* m_btnOK;
		
		enum NI_IDs
		{
			ID_text_name,
			ID_select_MC,
			ID_select_LWJGL,
			ID_show_old,
			ID_show_new,
			ID_icon_select
		};
		
		bool m_showOldSnapshots;
		bool m_showNewSnapshots;
		bool m_loadingDone;
		wxString m_iconKey;
		wxString m_visibleIconKey;
		wxString m_name;
		
	protected:
		void OnIcon(wxCommandEvent& event);
		void OnName(wxCommandEvent& event);
		void OnCheckbox(wxCommandEvent& event);
		
		void Refilter();
		
		void SetIconKey(wxString iconkey);
		void UpdateIcon();
		
	public:
		NewInstanceDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create New Instance"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 394,380 ), long style = wxDEFAULT_DIALOG_STYLE );
		~NewInstanceDialog();
		wxString GetInstanceName();
		wxString GetInstanceMCVersion();
		wxString GetInstanceLWJGL();
		wxString GetInstanceIconKey();
		int ShowModal();
	
	
	protected:
		DECLARE_EVENT_TABLE()
};

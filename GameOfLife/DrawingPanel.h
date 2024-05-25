#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include <wx/wx.h>
#include <vector>

class DrawingPanel : public wxPanel {
public:
    DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& gameBoard);
    ~DrawingPanel();
  
private:
    void OnPaint(wxPaintEvent& event);
    void OnMouseUp(wxMouseEvent& event);


    int gridSize;
    std::vector<std::vector<bool>>& gameBoard;

    wxDECLARE_EVENT_TABLE();
};

#endif
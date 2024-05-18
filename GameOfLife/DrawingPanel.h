#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include <wx/wx.h>
#include <wx/graphics.h>
#include <vector>

class DrawingPanel : public wxPanel {
public:
    DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& gameBoard);
    ~DrawingPanel();
  
    void SetGridSize(int size); // Method to set the grid size
    void SetSize(const wxSize& size);

private:
    void OnPaint(wxPaintEvent& event);
   
    void OnMouseUp(wxMouseEvent& event);


    int gridSize;
    std::vector<std::vector<bool>>& gameBoard;

    wxDECLARE_EVENT_TABLE();
};

#endif
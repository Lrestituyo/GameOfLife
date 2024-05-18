#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include <wx/wx.h>
#include <wx/graphics.h>
#include <vector>

class DrawingPanel : public wxPanel {
public:
    DrawingPanel(wxWindow* parent);
    ~DrawingPanel();
    void OnPaint(wxPaintEvent& event);
    void SetSize(const wxSize& size);
    void SetGridSize(int size); // Method to set the grid size
    void OnMouseUp(wxMouseEvent& event);

private:
    int gridSize;
    std::vector<std::vector<bool>>& gameBoard;
    wxDECLARE_EVENT_TABLE();
};

#endif
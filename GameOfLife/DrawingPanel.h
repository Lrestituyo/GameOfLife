#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include <wx/wx.h>
#include <wx/graphics.h>

class DrawingPanel : public wxPanel {
public:
    DrawingPanel(wxWindow* parent);
    ~DrawingPanel();
    void OnPaint(wxPaintEvent& event);
    void SetSize(const wxSize& size);
    void SetGridSize(int size); // Method to set the grid size

private:
    int gridSize;
    wxDECLARE_EVENT_TABLE();
};

#endif
#include "DrawingPanel.h"

wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
EVT_PAINT(DrawingPanel::OnPaint)
wxEND_EVENT_TABLE()

DrawingPanel::DrawingPanel(wxWindow* parent)
    : wxPanel(parent), gridSize(15) {
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
}

DrawingPanel::~DrawingPanel()
{
}

void DrawingPanel::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    dc.Clear();
    wxGraphicsContext* context = wxGraphicsContext::Create(dc);

    if (context) {
        context->SetPen(*wxBLACK_PEN);
        wxBrush whiteBrush(*wxWHITE_BRUSH);
        context->SetBrush(whiteBrush);

        // Calculate cell width and cell height
        wxSize panelSize = GetSize();
        int cellWidth = panelSize.GetWidth() / gridSize;
        int cellHeight = panelSize.GetHeight() / gridSize;

        // Draw grid of rectangles
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                int x = j * cellWidth;
                int y = i * cellHeight;
                context->DrawRectangle(x, y, cellWidth, cellHeight);
            }
        }

        delete context;
    }
}

void DrawingPanel::SetSize(const wxSize& size) {
    wxPanel::SetSize(size); // Call the base class SetSize method
    Refresh(); // Refresh the panel to trigger OnPaint
}

void DrawingPanel::SetGridSize(int size)
{
    gridSize = size;
    Refresh();
}





#include "DrawingPanel.h"

DrawingPanel::DrawingPanel(wxWindow* parent)
	: wxPanel(parent)
{
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
}

DrawingPanel::~DrawingPanel() {


}
void DrawingPanel::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    wxGraphicsContext* context = wxGraphicsContext::Create(dc);

    if (context) {
        context->SetPen(*wxBLACK_PEN);
        wxBrush whiteBrush(*wxWHITE);
        context->SetBrush(whiteBrush);

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




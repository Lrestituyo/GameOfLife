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
	context = wxGraphicsContext::Create(dc);
	if (!context) {

		context->SetPen(*wxBLACK_PEN);
		wxBrush whiteBrush(*wxWHITE);
		context->SetBrush(whiteBrush);
		
		int cellSize = 10;
		int gridSize = 15;

		for (int i = 0; i < gridSize; ++i) {
			for (int j = 0; j < gridSize; ++j) {
				int x = j * cellSize;
				int y = i * cellSize;
				context ->DrawRectangle(x, y, cellSize, cellSize);
			}
		}

		delete context;
	}



}
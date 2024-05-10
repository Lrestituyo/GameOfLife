#include "DrawingPanel.h"

DrawingPanel::DrawingPanel(wxWindow* parent)
	: wxPanel(parent)
{
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
}

DrawingPanel::~DrawingPanel() {
	delete context;

}
void DrawingPanel::OnPaint(wxPaintEvent& event) {
	wxPaintDC dc(this);
	wxGraphicsContext* context = wxGraphicsContext::Create(dc);
	context = wxGraphicsContext::Create(dc);
	if (!context) {

		context->SetPen(*wxBLACK_PEN);
		wxBrush whiteBrush(*wxWHITE);
		context->SetBrush(whiteBrush);
		context->DrawRectangle(10, 10, 60, 60);

		return;
	}



}
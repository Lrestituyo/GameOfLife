#ifndef DRAWINGPANEL_H
#define	DRAWINGPANEL_H

#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

class DrawingPanel : public wxPanel {
public:
	DrawingPanel(wxWindow* parent);
	~DrawingPanel();

	void OnPaint(wxPaintEvent& event);

private:
	int gridSize = 15;
};

#endif // !DRAWINGPANEL_H


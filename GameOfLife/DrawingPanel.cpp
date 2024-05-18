#include "DrawingPanel.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
EVT_PAINT(DrawingPanel::OnPaint)
EVT_LEFT_UP(DrawingPanel::OnMouseUp)
wxEND_EVENT_TABLE()

DrawingPanel::DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& gameBoard)
    : wxPanel(parent), gridSize(15), gameBoard(gameBoard)
{
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
}

DrawingPanel::~DrawingPanel()
{
}

void DrawingPanel::OnPaint(wxPaintEvent& event) {
   wxAutoBufferedPaintDC dc(this);
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

                if (gameBoard[i][j]) {
                    context->SetBrush(*wxLIGHT_GREY_BRUSH);
                }
                else {
                    context->SetBrush(*wxWHITE_BRUSH);
                }
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

void DrawingPanel::OnMouseUp(wxMouseEvent& event) {
    int mouseX = event.GetX();
    int mouseY = event.GetY();

    wxSize panelSize = GetSize();
    int cellWidth = panelSize.GetWidth() / gridSize;
    int cellHeight = panelSize.GetHeight() / gridSize;

    int col = mouseX / cellWidth;
    int row = mouseY / cellHeight;
    
    if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
        gameBoard[row][col] = !gameBoard[row][col];
    }
    Refresh();
}




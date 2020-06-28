#include "MyComponent.h"

using namespace CppWpfDemo;
using namespace System::Windows;
using namespace System::Windows::Controls;
using namespace System::Windows::Media;

[System::STAThreadAttribute]
int main(array<System::String^>^ args)
{
	Application^ ap = gcnew Application();
	Window^ w = gcnew Window();
	w->Title = "C++/CLI WPF demo";

	TextBlock^ tb = gcnew TextBlock();
	tb->Text = "Hello WPF";

	// Add root Grid
	Grid^ rootGrid = gcnew Grid();
	rootGrid->Width = 120;
	rootGrid->Height = 120;
	RowDefinition^ myRowDef1 = gcnew RowDefinition();
	rootGrid->RowDefinitions->Add(myRowDef1);

	DataGrid^ grid = gcnew DataGrid();
	grid->Background = Brushes::LightBlue;
	grid->Width = 80;
	grid->Height = 100;

	// Define the Canvas
	Canvas^ mainCanvas = gcnew Canvas();
	mainCanvas->Children->Add(tb);
	mainCanvas->Children->Add(grid);

	Canvas::SetTop(tb, 20);
	Canvas::SetLeft(tb, 20);

	Canvas::SetTop(grid, 50);
	Canvas::SetLeft(grid, 20);

	rootGrid->Children->Add(mainCanvas);
	Grid::SetRow(mainCanvas, 0);

	w->Content = rootGrid;
	ap->Run(w);

	return 0;
}

#pragma once

namespace lz231 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Лінія", L"Прямокутник", L"Зафарбований прямокутник",
					L"Еліпс", L"Зафарбований еліпс", L"Сектор", L"Зірка", L"Трикутник", L"Будиночок"
			});
			this->listBox1->Location = System::Drawing::Point(308, 40);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(178, 160);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Червоний", L"Зелений", L"Синій", L"Жовтий" });
			this->comboBox1->Location = System::Drawing::Point(308, 226);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 381);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graf = CreateGraphics();
		graf->Clear(Color::White);
		Pen^ pn = gcnew System::Drawing::Pen(Color::Blue, 5);
		Brush^ br = gcnew System::Drawing::SolidBrush(Color::DarkRed);
		Color userColor = Color::Black;
		switch (comboBox1->SelectedIndex) {
		case 0: userColor = Color::Red; break;
		case 1: userColor = Color::Green; break;
		case 2: userColor = Color::Blue; break;
		case 3: userColor = Color::Yellow; break;
		}
		Pen^ userPen = gcnew System::Drawing::Pen(userColor, 5);
		Brush^ userBrush = gcnew System::Drawing::SolidBrush(userColor);
		switch (listBox1->SelectedIndex)
		{
		case 0: graf->DrawLine(gcnew System::Drawing::Pen(Color::Green, 8), 50, 40, 250, 160); break;
		case 1: graf->DrawRectangle(Pens::Red, 40, 40, 150, 80); break;
		case 2: graf->FillRectangle(Brushes::Green, 40, 40, 150, 80); break;
		case 3: graf->DrawEllipse(Pens::Purple, 40, 40, 200, 140); break;
		case 4: graf->FillEllipse(Brushes::LightBlue, 40, 40, 200, 140); break;
		case 5: graf->FillPie(Brushes::Brown, 40, 40, 200, 200, 180, 90); break;
		case 6: {
			cli::array<Point>^ starPoints = gcnew cli::array<Point>{
				Point(120, 30), Point(145, 100), Point(215, 100),
					Point(155, 150), Point(180, 230), Point(120, 180),
					Point(60, 230), Point(85, 150), Point(25, 100), Point(95, 100)
			};
			graf->FillPolygon(Brushes::Yellow, starPoints);
			graf->DrawPolygon(Pens::Yellow, starPoints);
		} break;

		case 7: {
			cli::array<Point>^ trianglePoints = gcnew cli::array<Point>{
				Point(150, 50), Point(100, 150), Point(200, 150)
			};
			graf->DrawPolygon(Pens::Black, trianglePoints);
		} break;

		case 8: {
			graf->DrawRectangle(userPen, 100, 100, 120, 100);

			cli::array<Point>^ roofPoints = gcnew cli::array<Point>{
				Point(90, 100), Point(160, 40), Point(230, 100)
			};
			graf->DrawPolygon(userPen, roofPoints);
			graf->DrawRectangle(userPen, 140, 140, 40, 60);
		} break;
		}
	}
	};
}
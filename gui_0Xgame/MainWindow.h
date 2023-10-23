#pragma once

bool firstsRound{ true };

namespace gui0Xgame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txb1;
	private: System::Windows::Forms::TextBox^ txb2;
	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn6;




	private: System::Windows::Forms::Button^ btn5;

	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn9;


	private: System::Windows::Forms::Button^ btn8;

	private: System::Windows::Forms::Button^ btn7;
	private: System::Windows::Forms::Label^ lbl;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txb1 = (gcnew System::Windows::Forms::TextBox());
			this->txb2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->lbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"1. játékos:";
			// 
			// txb1
			// 
			this->txb1->Location = System::Drawing::Point(12, 35);
			this->txb1->Name = L"txb1";
			this->txb1->Size = System::Drawing::Size(100, 20);
			this->txb1->TabIndex = 1;
			this->txb1->TextChanged += gcnew System::EventHandler(this, &MainWindow::txb1_TextChanged);
			// 
			// txb2
			// 
			this->txb2->Location = System::Drawing::Point(149, 35);
			this->txb2->Name = L"txb2";
			this->txb2->Size = System::Drawing::Size(100, 20);
			this->txb2->TabIndex = 3;
			this->txb2->TextChanged += gcnew System::EventHandler(this, &MainWindow::txb2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(152, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"2. játékos:";
			// 
			// btn1
			// 
			this->btn1->Location = System::Drawing::Point(12, 74);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(75, 75);
			this->btn1->TabIndex = 4;
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &MainWindow::btn1_Click);
			// 
			// btn2
			// 
			this->btn2->Location = System::Drawing::Point(93, 74);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(75, 75);
			this->btn2->TabIndex = 5;
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &MainWindow::btn2_Click);
			// 
			// btn3
			// 
			this->btn3->Location = System::Drawing::Point(174, 74);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(75, 75);
			this->btn3->TabIndex = 6;
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &MainWindow::btn3_Click);
			// 
			// btn6
			// 
			this->btn6->Location = System::Drawing::Point(174, 155);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(75, 75);
			this->btn6->TabIndex = 9;
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &MainWindow::btn6_Click);
			// 
			// btn5
			// 
			this->btn5->Location = System::Drawing::Point(93, 155);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(75, 75);
			this->btn5->TabIndex = 8;
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &MainWindow::btn5_Click);
			// 
			// btn4
			// 
			this->btn4->Location = System::Drawing::Point(12, 155);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(75, 75);
			this->btn4->TabIndex = 7;
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &MainWindow::btn4_Click);
			// 
			// btn9
			// 
			this->btn9->Location = System::Drawing::Point(174, 236);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(75, 75);
			this->btn9->TabIndex = 12;
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &MainWindow::btn9_Click);
			// 
			// btn8
			// 
			this->btn8->Location = System::Drawing::Point(93, 236);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(75, 75);
			this->btn8->TabIndex = 11;
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &MainWindow::btn8_Click);
			// 
			// btn7
			// 
			this->btn7->Location = System::Drawing::Point(12, 236);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(75, 75);
			this->btn7->TabIndex = 10;
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &MainWindow::btn7_Click);
			// 
			// lbl
			// 
			this->lbl->AutoSize = true;
			this->lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->lbl->Location = System::Drawing::Point(15, 324);
			this->lbl->MinimumSize = System::Drawing::Size(230, 20);
			this->lbl->Name = L"lbl";
			this->lbl->Size = System::Drawing::Size(230, 24);
			this->lbl->TabIndex = 13;
			this->lbl->Text = L"Az 1. játékos jön.";
			this->lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(263, 356);
			this->Controls->Add(this->lbl);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->txb2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txb1);
			this->Controls->Add(this->label1);
			this->Name = L"MainWindow";
			this->Text = L"zéró-iksz játék";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void WhosRound() {
		if (firstsRound) {
			if (txb1->Text != "") {
				lbl->Text = txb1->Text + " jön.";
			}
			else {
				lbl->Text = "Az 1. játékos jön.";
			}
		}
		else {
			if (txb2->Text != "") {
				lbl->Text = txb2->Text + " jön.";
			}
			else {
				lbl->Text = "Az 2. játékos jön.";
			}
		}

	}
	private: System::Void txb1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		WhosRound();
	}
	private: System::Void txb2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		WhosRound();
	}
	private: System::Void btn1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn1->Text == "") {
			btn1->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
	private: System::Void btn2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn2->Text == "") {
			btn2->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
	private: System::Void btn3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn3->Text == "") {
			btn3->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
	private: System::Void btn4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn4->Text == "") {
			btn4->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
	private: System::Void btn5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn5->Text == "") {
			btn5->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
	private: System::Void btn6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn6->Text == "") {
			btn6->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
	private: System::Void btn7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn7->Text == "") {
			btn7->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
	private: System::Void btn8_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn8->Text == "") {
			btn8->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
	private: System::Void btn9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn9->Text == "") {
			btn9->Text = (firstsRound) ? "0" : "X";
			firstsRound = !firstsRound;
			WhosRound();
		}
	}
};
}

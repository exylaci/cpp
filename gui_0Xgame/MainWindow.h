#include <string>
#include <msclr\marshal_cppstd.h>
#pragma once

bool firstsRound{ true };
int cells[9]{ 0 };
std::string firstName{ "" };
std::string secondName{ "" };

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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txb2;
	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn5;
	private: System::Windows::Forms::Button^ btn6;
	private: System::Windows::Forms::Button^ btn8;
	private: System::Windows::Forms::Button^ btn7;
	private: System::Windows::Forms::Button^ btn9;
	private: System::Windows::Forms::Label^ lbl;
	private: System::Windows::Forms::Button^ btn_newGame;
	private: System::Windows::Forms::CheckBox^ chk1;
	private: System::Windows::Forms::CheckBox^ chk2;





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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txb2 = (gcnew System::Windows::Forms::TextBox());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->lbl = (gcnew System::Windows::Forms::Label());
			this->btn_newGame = (gcnew System::Windows::Forms::Button());
			this->chk1 = (gcnew System::Windows::Forms::CheckBox());
			this->chk2 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(15, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"1. j�t�kos:";
			// 
			// txb1
			// 
			this->txb1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->txb1->Location = System::Drawing::Point(12, 26);
			this->txb1->Name = L"txb1";
			this->txb1->Size = System::Drawing::Size(100, 22);
			this->txb1->TabIndex = 1;
			this->txb1->TextChanged += gcnew System::EventHandler(this, &MainWindow::txb_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(152, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"2. j�t�kos:";
			// 
			// txb2
			// 
			this->txb2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->txb2->Location = System::Drawing::Point(149, 26);
			this->txb2->Name = L"txb2";
			this->txb2->Size = System::Drawing::Size(100, 22);
			this->txb2->TabIndex = 3;
			this->txb2->TextChanged += gcnew System::EventHandler(this, &MainWindow::txb_TextChanged);
			// 
			// btn1
			// 
			this->btn1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn1->ForeColor = System::Drawing::Color::Red;
			this->btn1->Location = System::Drawing::Point(12, 75);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(75, 75);
			this->btn1->TabIndex = 4;
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// btn2
			// 
			this->btn2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn2->ForeColor = System::Drawing::Color::Black;
			this->btn2->Location = System::Drawing::Point(93, 75);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(75, 75);
			this->btn2->TabIndex = 5;
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// btn3
			// 
			this->btn3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn3->Location = System::Drawing::Point(174, 75);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(75, 75);
			this->btn3->TabIndex = 6;
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// btn4
			// 
			this->btn4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn4->Location = System::Drawing::Point(12, 156);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(75, 75);
			this->btn4->TabIndex = 7;
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// btn5
			// 
			this->btn5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn5->Location = System::Drawing::Point(93, 156);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(75, 75);
			this->btn5->TabIndex = 8;
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// btn6
			// 
			this->btn6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn6->Location = System::Drawing::Point(174, 156);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(75, 75);
			this->btn6->TabIndex = 9;
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// btn7
			// 
			this->btn7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn7->Location = System::Drawing::Point(12, 237);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(75, 75);
			this->btn7->TabIndex = 10;
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// btn8
			// 
			this->btn8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn8->Location = System::Drawing::Point(93, 237);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(75, 75);
			this->btn8->TabIndex = 11;
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// btn9
			// 
			this->btn9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn9->Location = System::Drawing::Point(174, 237);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(75, 75);
			this->btn9->TabIndex = 12;
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &MainWindow::btn_Click);
			// 
			// lbl
			// 
			this->lbl->AutoSize = true;
			this->lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->lbl->Location = System::Drawing::Point(15, 325);
			this->lbl->MinimumSize = System::Drawing::Size(230, 20);
			this->lbl->Name = L"lbl";
			this->lbl->Size = System::Drawing::Size(230, 24);
			this->lbl->TabIndex = 13;
			this->lbl->Text = L"Az 1. j�t�kos j�n.";
			this->lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_newGame
			// 
			this->btn_newGame->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn_newGame->ForeColor = System::Drawing::Color::Coral;
			this->btn_newGame->Location = System::Drawing::Point(12, 353);
			this->btn_newGame->Name = L"btn_newGame";
			this->btn_newGame->Size = System::Drawing::Size(237, 40);
			this->btn_newGame->TabIndex = 14;
			this->btn_newGame->Text = L"�j j�t�k";
			this->btn_newGame->UseVisualStyleBackColor = true;
			this->btn_newGame->Visible = false;
			this->btn_newGame->Click += gcnew System::EventHandler(this, &MainWindow::btn_newGame_Click);
			// 
			// chk1
			// 
			this->chk1->AutoSize = true;
			this->chk1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->chk1->Location = System::Drawing::Point(12, 52);
			this->chk1->Name = L"chk1";
			this->chk1->Size = System::Drawing::Size(84, 20);
			this->chk1->TabIndex = 15;
			this->chk1->Text = L"Computer";
			this->chk1->UseVisualStyleBackColor = true;
			this->chk1->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::chk1_CheckedChanged);
			// 
			// chk2
			// 
			this->chk2->AutoSize = true;
			this->chk2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->chk2->Location = System::Drawing::Point(149, 52);
			this->chk2->Name = L"chk2";
			this->chk2->Size = System::Drawing::Size(84, 20);
			this->chk2->TabIndex = 16;
			this->chk2->Text = L"Computer";
			this->chk2->UseVisualStyleBackColor = true;
			this->chk2->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::checkBox1_CheckedChanged);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(263, 404);
			this->Controls->Add(this->chk2);
			this->Controls->Add(this->chk1);
			this->Controls->Add(this->btn_newGame);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txb1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbl);
			this->Controls->Add(this->txb2);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn9);
			this->Name = L"MainWindow";
			this->Text = L"z�r�-iksz j�t�k";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Button^ getButton(int order) {
		switch (order) {
		case 1:
			return btn1;
		case 2:
			return btn2;
		case 3:
			return btn3;
		case 4:
			return btn4;
		case 5:
			return btn5;
		case 6:
			return btn6;
		case 7:
			return btn7;
		case 8:
			return btn8;
		case 9:
			return btn9;
		}
	}
	private: void setButtonsDisabled() {
		for (int i{ 1 }; i < 10; ++i) {
			Button^ btn = getButton(i);
			btn->Enabled = false;
		}
	}
	private: void storeOneStep(Button^ btn) {
		btn->Text = (firstsRound) ? "0" : "X";
		btn->ForeColor = (firstsRound) ? System::Drawing::Color::Red : System::Drawing::Color::Black;
		cells[System::Convert::ToInt32(btn->Name->Substring(3, 1)) - 1] =
			firstsRound ? 1 : 2;
	}
	private: bool isEmpty() {
		for (int i{ 0 }; i < 9; ++i) {
			if (cells[i] != 0) {
				return false;
			}
		}
		return true;
	}
	private: int isDouble(int what) {
		for (int i{ 0 }; i < 3; ++i) {
			if (cells[i] == what && cells[3 + i] == what && cells[6 + i] == 0) {
				return 6 + i;
			}
			if (cells[i] == what && cells[3 + i] == 0 && cells[6 + i] == what) {
				return 3 + i;
			}
			if (cells[i] == 0 && cells[3 + i] == what && cells[6 + i] == what) {
				return  i;
			}
			if (cells[i * 3] == what && cells[1 + i * 3] == what && cells[2 + i * 3] == 0) {
				return 2 + i * 3;
			}
			if (cells[i * 3] == what && cells[1 + i * 3] == 0 && cells[2 + i * 3] == what) {
				return 1 + i * 3;
			}
			if (cells[i * 3] == 0 && cells[1 + i * 3] == what && cells[2 + i * 3] == what) {
				return i * 3;
			}
		}
		if (cells[0] == what && cells[4] == what && cells[8] == 0) {
			return 8;
		}
		if (cells[0] == what && cells[4] == 0 && cells[8] == what) {
			return 4;
		}
		if (cells[0] == 0 && cells[4] == what && cells[8] == what) {
			return 0;
		}
		if (cells[2] == what && cells[4] == what && cells[6] == 0) {
			return 6;
		}
		if (cells[2] == what && cells[4] == 0 && cells[6] == what) {
			return 4;
		}
		if (cells[2] == 0 && cells[4] == what && cells[6] == what) {
			return 2;
		}
		return -1;
	}
	private: int isInCorner(int what) {
		if (cells[0] == what && cells[1] == 0 && cells[3] == 0) {
			return 1;
		}
		if (cells[2] == what && cells[1] == 0 && cells[5] == 0) {
			return 1;
		}
		if (cells[6] == what && cells[7] == 0 && cells[3] == 0) {
			return 7;
		}
		if (cells[8] == what && cells[7] == 0 && cells[5] == 0) {
			return 7;
		}
		return -1;
	}
	private: int isOnSide(int what) {
		if (cells[1] == what && cells[0] == 0 && cells[2] == 0) {
			return 0;
		}
		if (cells[3] == what && cells[0] == 0 && cells[6] == 0) {
			return 0;
		}
		if (cells[5] == what && cells[2] == 0 && cells[8] == 0) {
			return 8;
		}
		if (cells[7] == what && cells[6] == 0 && cells[8] == 0) {
			return 8;
		}
		return -1;
	}
	private: int toCorner() {
		if (cells[0] == 0) {
			return 0;
		}
		if (cells[2] == 0) {
			return 2;
		}
		if (cells[6] == 0) {
			return 6;
		}
		if (cells[8] == 0) {
			return 8;
		}
	}
	private: void computersStep() {
		int what{ firstsRound ? 1 : 2 };
		if (isEmpty()) {
			storeOneStep(getButton(5));
			return;
		}
		int where{ isDouble(what) };
		if (where >= 0) {
			storeOneStep(getButton(where + 1));
			return;
		}
		where = isDouble(3 - what);
		if (where >= 0) {
			storeOneStep(getButton(where + 1));
			return;
		}
		if (cells[4] == 0) {
			storeOneStep(getButton(5));
			return;
		}
		where = isInCorner(3 - what);
		if (where >= 0) {
			storeOneStep(getButton(where + 1));
			return;
		}
		where = isOnSide(3 - what);
		if (where >= 0) {
			storeOneStep(getButton(where + 1));
			return;
		}
		where = isInCorner(what);
		if (where >= 0) {
			storeOneStep(getButton(where + 1));
			return;
		}
		where = isOnSide(what);
		if (where >= 0) {
			storeOneStep(getButton(where + 1));
			return;
		}
		where = toCorner();
		if (where >= 0) {
			storeOneStep(getButton(where + 1));
			return;
		}
		for (int i{ 0 }; i < 9; ++i) {
			if (cells[i] == 0) {
				storeOneStep(getButton(i + 1));
				return;
			}
		}
	}
	private: void WhosRound() {
		if (firstsRound) {
			if (txb1->Text != "") {
				lbl->Text = txb1->Text + " j�n.";
			}
			else {
				lbl->Text = "Az 1. j�t�kos j�n.";
			}
		}
		else {
			if (txb2->Text != "") {
				lbl->Text = txb2->Text + " j�n.";
			}
			else {
				lbl->Text = "A 2. j�t�kos j�n.";
			}
		}
	}
	private: int Checking() {
		for (int i{ 0 }; i < 3; ++i) {
			if (cells[i * 3] != 0 && cells[i * 3] == cells[1 + i * 3] && cells[i * 3] == cells[2 + i * 3]) {
				return cells[i * 3];
			}
			if (cells[i] != 0 && cells[i] == cells[3 + i] && cells[i] == cells[6 + i]) {
				return cells[i];
			}
		}
		if ((cells[4] != 0 && cells[4] == cells[0] && cells[4] == cells[8]) ||
			(cells[4] != 0 && cells[4] == cells[2] && cells[4] == cells[6])) {
			return cells[4];
		}
		for (int i = 0; i < 9; ++i) {
			if (cells[i] == 0) {
				return 0;
			}
		}
		return 3;
	}
	private: void win(int who) {
		switch (who) {
		case 1: {
			if (txb1->Text != "") {
				lbl->Text = txb1->Text + " nyert!";
			}
			else {
				lbl->Text = "Az 1. j�t�kos nyert.";
			}
			break; }
		case 2: {
			if (txb2->Text != "") {
				lbl->Text = txb2->Text + " nyert!";
			}
			else {
				lbl->Text = "A 2. j�t�kos nyert!";
			}
			break; }
		default:
			lbl->Text = "D�ntetlen.";

		}
		setButtonsDisabled();
		btn_newGame->Visible = true;
	}
	private: void Rounds() {
		do {
			if (firstsRound) {
				if (txb1->Text != "Computer") {
					break;
				}
			}
			else
				if (txb2->Text != "Computer") {
					break;
				}
			computersStep();
			int resoult{ Checking() };
			if (resoult != 0) {
				win(resoult);
				break;
			}
			firstsRound = !firstsRound;
			WhosRound();
		} while (true);
	}
	private: System::Void txb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		WhosRound();
		Rounds();
	}
	private: System::Void btn_Click(System::Object^ sender, System::EventArgs^ e) {
		auto btn = ((Button^)sender);
		if (btn->Text == "") {
			storeOneStep(btn);
			int resoult{ Checking() };
			if (resoult != 0) {
				win(resoult);
			}
			else {
				firstsRound = !firstsRound;
				WhosRound();
			}
		}
		Rounds();
	}
	private: System::Void btn_newGame_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 9; ++i) {
			cells[i] = 0;
			Button^ btn{ getButton(i + 1) };
			btn->Enabled = true;
			btn->Text = "";
		}
		btn_newGame->Visible = false;
		firstsRound = !firstsRound;
		WhosRound();
		Rounds();
	}
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void chk1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (chk1->Checked) {
			firstName = msclr::interop::marshal_as<std::string>(txb1->Text);
			txb1->Text = "Computer";
		}
		else {
			txb1->Text = gcnew System::String(firstName.c_str());
		}
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (chk2->Checked) {
			secondName = msclr::interop::marshal_as<std::string>(txb2->Text);
			txb2->Text = "Computer";
		}
		else {
			txb2->Text = gcnew System::String(secondName.c_str());
		}
	}
	};
}

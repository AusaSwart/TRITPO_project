#pragma once

namespace Library {

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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ Button_Delete;



	private: System::Windows::Forms::Button^ Button_Add;

	private: System::Windows::Forms::Button^ Button_Download;




	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FIO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BookName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Book_Author;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Data_Of_Borroving;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Data_Of_Returning;
	private: System::Windows::Forms::Button^ Button_Exit;
	private: System::Windows::Forms::Button^ Button_Update;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->FIO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BookName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Book_Author = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Data_Of_Borroving = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Data_Of_Returning = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Button_Update = (gcnew System::Windows::Forms::Button());
			this->Button_Exit = (gcnew System::Windows::Forms::Button());
			this->Button_Delete = (gcnew System::Windows::Forms::Button());
			this->Button_Add = (gcnew System::Windows::Forms::Button());
			this->Button_Download = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->FIO, this->BookName,
					this->Book_Author, this->Data_Of_Borroving, this->Data_Of_Returning
			});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(545, 223);
			this->dataGridView1->TabIndex = 0;
			// 
			// FIO
			// 
			this->FIO->HeaderText = L"FIO";
			this->FIO->Name = L"FIO";
			// 
			// BookName
			// 
			this->BookName->HeaderText = L"Title";
			this->BookName->Name = L"BookName";
			// 
			// Book_Author
			// 
			this->Book_Author->HeaderText = L"Author";
			this->Book_Author->Name = L"Book_Author";
			// 
			// Data_Of_Borroving
			// 
			this->Data_Of_Borroving->HeaderText = L"Data";
			this->Data_Of_Borroving->Name = L"Data_Of_Borroving";
			// 
			// Data_Of_Returning
			// 
			this->Data_Of_Returning->HeaderText = L"Return";
			this->Data_Of_Returning->Name = L"Data_Of_Returning";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Button_Update);
			this->groupBox1->Controls->Add(this->Button_Exit);
			this->groupBox1->Controls->Add(this->Button_Delete);
			this->groupBox1->Controls->Add(this->Button_Add);
			this->groupBox1->Controls->Add(this->Button_Download);
			this->groupBox1->ForeColor = System::Drawing::Color::Indigo;
			this->groupBox1->Location = System::Drawing::Point(563, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(103, 221);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Actions";
			// 
			// Button_Update
			// 
			this->Button_Update->ForeColor = System::Drawing::Color::DarkGreen;
			this->Button_Update->Location = System::Drawing::Point(6, 69);
			this->Button_Update->Name = L"Button_Update";
			this->Button_Update->Size = System::Drawing::Size(86, 23);
			this->Button_Update->TabIndex = 5;
			this->Button_Update->Text = L"Update";
			this->Button_Update->UseVisualStyleBackColor = true;
			this->Button_Update->Click += gcnew System::EventHandler(this, &MyForm::Button_Update_Click);
			// 
			// Button_Exit
			// 
			this->Button_Exit->ForeColor = System::Drawing::Color::DarkGreen;
			this->Button_Exit->Location = System::Drawing::Point(6, 193);
			this->Button_Exit->Name = L"Button_Exit";
			this->Button_Exit->Size = System::Drawing::Size(86, 22);
			this->Button_Exit->TabIndex = 4;
			this->Button_Exit->Text = L"Exit";
			this->Button_Exit->UseVisualStyleBackColor = true;
			this->Button_Exit->Click += gcnew System::EventHandler(this, &MyForm::Button_Exit_Click);
			// 
			// Button_Delete
			// 
			this->Button_Delete->ForeColor = System::Drawing::Color::DarkGreen;
			this->Button_Delete->Location = System::Drawing::Point(6, 154);
			this->Button_Delete->Name = L"Button_Delete";
			this->Button_Delete->Size = System::Drawing::Size(86, 22);
			this->Button_Delete->TabIndex = 3;
			this->Button_Delete->Text = L"Delete";
			this->Button_Delete->UseVisualStyleBackColor = true;
			this->Button_Delete->Click += gcnew System::EventHandler(this, &MyForm::Button_Delete_Click);
			// 
			// Button_Add
			// 
			this->Button_Add->ForeColor = System::Drawing::Color::DarkGreen;
			this->Button_Add->Location = System::Drawing::Point(6, 111);
			this->Button_Add->Name = L"Button_Add";
			this->Button_Add->Size = System::Drawing::Size(86, 22);
			this->Button_Add->TabIndex = 1;
			this->Button_Add->Text = L"Add";
			this->Button_Add->UseVisualStyleBackColor = true;
			this->Button_Add->Click += gcnew System::EventHandler(this, &MyForm::Button_Add_Click);
			// 
			// Button_Download
			// 
			this->Button_Download->ForeColor = System::Drawing::Color::DarkGreen;
			this->Button_Download->Location = System::Drawing::Point(6, 28);
			this->Button_Download->Name = L"Button_Download";
			this->Button_Download->Size = System::Drawing::Size(86, 22);
			this->Button_Download->TabIndex = 0;
			this->Button_Download->Text = L"Download";
			this->Button_Download->UseVisualStyleBackColor = true;
			this->Button_Download->Click += gcnew System::EventHandler(this, &MyForm::Button_Download_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Teal;
			this->ClientSize = System::Drawing::Size(677, 246);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Library DataBase";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
private: System::Void Button_Download_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Button_Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Button_Update_Click(System::Object^ sender, System::EventArgs^ e);
};
}

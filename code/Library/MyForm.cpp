#include "MyForm.h"

using namespace System;                        // пространства имен 
using namespace System::Windows::Forms;        // для работы с формой
using namespace System::Data::OleDb;          //подкл. про-ва имен для управления бд

[STAThread]   // указываем, что работаем с потоками

int main(array<String^>^ arg) { 
	Application::EnableVisualStyles();                          // параметры 
	Application::SetCompatibleTextRenderingDefault(false);      // для запуска

	Library::MyForm form;  
	Application::Run(% form);    //запуск окна 

}

System::Void Library::MyForm::Button_Download_Click(System::Object^ sender, System::EventArgs^ e)
{
	//подключение к БД
	//строка подкл-я
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseOfLibrary.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	// запрос к БД
	dbConnection->Open(); // открываем соединение
	String^ query = "SELECT * FROM [table_name]"; // запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); // команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); // считываем данные

	//проверяем данные
	if (dbReader->HasRows == false) {
		MessageBox::Show("Error reading of data!", "Error!");
	}
	else {
		//Заполним данные в таблицу
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["FIO"], dbReader["Title"], dbReader["Author"], dbReader["Data"], dbReader["Return"]);
		}
	}

	//Закрываем соединение
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void Library::MyForm::Button_Update_Click(System::Object^ sender, System::EventArgs^ e) {
	// выбор нужной строки добавления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Choose row for adding", "Warning");
		return;
	}

	// узнаеем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	// проверяем данные
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr
		) {
		MessageBox::Show("Not all data entered", "Warning");
		return;
	}

	// Считываем данные 
	String^ FIO = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Title = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Author = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Data = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Return = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//подключение к БД
	//строка подкл-я
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseOfLibrary.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	// запрос к БД
	dbConnection->Open(); // открываем соединение
	String^ query = "UPDATE [table_name] SET Title ='" + Title + "', Author = '" + Author + "', Data = '" + Data + "', Return ='" + Return + "' WHERE FIO = '" + FIO + "'";   // запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); // команда

	//выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request execution error", " Error");
	else
		MessageBox::Show("Data is updateded", "Done");

	//звкрываем соединение
	dbConnection->Close();

	return System::Void();
}

System::Void Library::MyForm::Button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки добавления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Choose row for adding", "Warning");
		return;
	}

	// узнаеем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	// проверяем данные
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr
		) {
		MessageBox::Show("Not all data entered", "Warning");
		return;
	}

	// Считываем данные 
	String^ FIO = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Title = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Author = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Data = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Return = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//подключение к БД
	//строка подкл-я
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseOfLibrary.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	// запрос к БД
	dbConnection->Open(); // открываем соединение
	String^ query = "INSERT INTO [table_name] VALUES ('"+ FIO +"', '"+ Title +"', '"+ Author +"', '"+ Data +"', '"+ Return +"')"; // запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); // команда

	//выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request execution error", " Error");
	else
		MessageBox::Show("Data is added", "Done");

	//звкрываем соединение
	dbConnection->Close();

	return System::Void();
}

System::Void Library::MyForm::Button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Library::MyForm::backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
{
	return System::Void();
}


System::Void Library::MyForm::Button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	// выбор нужной строки для удаления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Choose row for clearing", "Warning");
		return;
	}

	// узнаеем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;


	// проверяем данные
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr) {
		MessageBox::Show("Not all data entered", "Warning");
		return;
	}

	// Считываем данные 
	String^ FIO = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	//подключение к БД
	//строка подкл-я
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseOfLibrary.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	// запрос к БД
	dbConnection->Open(); // открываем соединение
	String^ query = "DELETE FROM [table_name] WHERE FIO = '" + FIO + "'";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); // команда

	//выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request execution error", " Error");
	else {
		MessageBox::Show("Data is deleted", "Done");
		dataGridView1->Rows->RemoveAt(index); //удаляем из самой бд (таблицы)
	}

	//Закрываем соединение
	dbConnection->Close();

	return System::Void();

}
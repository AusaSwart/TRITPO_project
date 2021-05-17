#include "MyForm.h"

using namespace System;                        // ������������ ���� 
using namespace System::Windows::Forms;        // ��� ������ � ������
using namespace System::Data::OleDb;          //�����. ���-�� ���� ��� ���������� ��

[STAThread]   // ���������, ��� �������� � ��������

int main(array<String^>^ arg) { 
	Application::EnableVisualStyles();                          // ��������� 
	Application::SetCompatibleTextRenderingDefault(false);      // ��� �������

	Library::MyForm form;  
	Application::Run(% form);    //������ ���� 

}

System::Void Library::MyForm::Button_Download_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����������� � ��
	//������ �����-�
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseOfLibrary.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	// ������ � ��
	dbConnection->Open(); // ��������� ����������
	String^ query = "SELECT * FROM [table_name]"; // ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); // �������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); // ��������� ������

	//��������� ������
	if (dbReader->HasRows == false) {
		MessageBox::Show("Error reading of data!", "Error!");
	}
	else {
		//�������� ������ � �������
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["FIO"], dbReader["Title"], dbReader["Author"], dbReader["Data"], dbReader["Return"]);
		}
	}

	//��������� ����������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void Library::MyForm::Button_Update_Click(System::Object^ sender, System::EventArgs^ e) {
	// ����� ������ ������ ����������
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Choose row for adding", "Warning");
		return;
	}

	// ������� ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	// ��������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr
		) {
		MessageBox::Show("Not all data entered", "Warning");
		return;
	}

	// ��������� ������ 
	String^ FIO = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Title = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Author = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Data = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Return = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//����������� � ��
	//������ �����-�
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseOfLibrary.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	// ������ � ��
	dbConnection->Open(); // ��������� ����������
	String^ query = "UPDATE [table_name] SET Title ='" + Title + "', Author = '" + Author + "', Data = '" + Data + "', Return ='" + Return + "' WHERE FIO = '" + FIO + "'";   // ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); // �������

	//��������� ������
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request execution error", " Error");
	else
		MessageBox::Show("Data is updateded", "Done");

	//��������� ����������
	dbConnection->Close();

	return System::Void();
}

System::Void Library::MyForm::Button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ����� ������ ������ ����������
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Choose row for adding", "Warning");
		return;
	}

	// ������� ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	// ��������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr
		) {
		MessageBox::Show("Not all data entered", "Warning");
		return;
	}

	// ��������� ������ 
	String^ FIO = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Title = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Author = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Data = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Return = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//����������� � ��
	//������ �����-�
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseOfLibrary.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	// ������ � ��
	dbConnection->Open(); // ��������� ����������
	String^ query = "INSERT INTO [table_name] VALUES ('"+ FIO +"', '"+ Title +"', '"+ Author +"', '"+ Data +"', '"+ Return +"')"; // ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); // �������

	//��������� ������
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request execution error", " Error");
	else
		MessageBox::Show("Data is added", "Done");

	//��������� ����������
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
	// ����� ������ ������ ��� ��������
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Choose row for clearing", "Warning");
		return;
	}

	// ������� ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;


	// ��������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr) {
		MessageBox::Show("Not all data entered", "Warning");
		return;
	}

	// ��������� ������ 
	String^ FIO = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	//����������� � ��
	//������ �����-�
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseOfLibrary.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	// ������ � ��
	dbConnection->Open(); // ��������� ����������
	String^ query = "DELETE FROM [table_name] WHERE FIO = '" + FIO + "'";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); // �������

	//��������� ������
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request execution error", " Error");
	else {
		MessageBox::Show("Data is deleted", "Done");
		dataGridView1->Rows->RemoveAt(index); //������� �� ����� �� (�������)
	}

	//��������� ����������
	dbConnection->Close();

	return System::Void();

}
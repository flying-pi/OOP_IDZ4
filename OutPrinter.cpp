//
// Created by Yura Braiko on 17.11.16.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "OutPrinter.h"

PrintComposer *PrintComposer::add(IPrinter *newPrinter) {
    printers.push_back(newPrinter);
    return this;
}

void PrintComposer::printResult(const char *str, const unsigned int &operationResult, const unsigned int &firstArgument,
                                const unsigned int &secondArgument) {
    for (auto i:printers)
        i->printResult(str, operationResult, firstArgument, secondArgument);

}

void
PrintComposer::printResult(const char *str, const unsigned int &operationResult, const unsigned int &firstArgument) {
    for (auto i:printers)
        i->printResult(str, operationResult, firstArgument);

}

PrintComposer::~PrintComposer() {
    for (auto i:printers)
        delete i;
}

void IPrinter::getbin(unsigned int n, char *out) {
    for (int i = 0; i < 16; i++) {
        out[i] = n & 0x8000 ? '1' : '0';
        n = n << 1;
    }
    out[17] = '\0';
}

void
IPrinter::printResult(const char *str, const unsigned int &operationResult, const unsigned int &firstArgument,
                      const unsigned int &secondArgument) {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;

    char *binaryValue = new char[17];
    (*out) << ("�����:\n");
    (*out) << setfill(' ') << setw(18) << dec << firstArgument << " 0x" << setfill('0') << setw(8) << hex
           << firstArgument << " ";
    getbin(firstArgument, binaryValue);
    (*out) << binaryValue;
    (*out) << str << setfill(' ') << setw(10) << dec << secondArgument << " 0x" << setfill('0') << setw(8) << hex
           << secondArgument
           << " ";
    getbin(secondArgument, binaryValue);
    (*out) << binaryValue;
    (*out) << "\n==============================================\n";
    (*out) << setfill(' ') << setw(18) << dec << operationResult << " 0x" << setfill('0') << setw(8) << hex
           << operationResult << " ";
    getbin(operationResult, binaryValue);
    (*out) << binaryValue;
    (*out) << "\n";

    delete binaryValue;
}


void IPrinter::printResult(const char *str, const unsigned int &operationResult, const unsigned int &firstArgument) {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;

    char *binaryValue = new char[17];
    (*out) << ("�����:\n");

    (*out) << str << setfill(' ') << setw(9) << dec << firstArgument << " 0x" << setfill('0') << setw(8) << hex
           << firstArgument << " ";
    getbin(firstArgument, binaryValue);
    (*out) << binaryValue;
    (*out) << "\n==============================================\n";
    (*out) << setfill(' ') << setw(18) << dec << operationResult << " 0x" << setfill('0') << setw(8) << hex
           << operationResult << " ";
    getbin(operationResult, binaryValue);
    (*out) << binaryValue;
    (*out) << "\n";

    delete binaryValue;
}

void IPrinter::printInstruction() {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;
    (*out) << ("������������ ������.���������� ��������\n"\
            " 1-���������� �������� � (&)\n"\
            " 2-���������� �������� ��� (|)\n"\
            " 3-���������� �������� ����.��� (^)\n"\
            " 4-���������� �������� ���.����� ����� (<<)\n"\
            " 5-���������� �������� ���.����� ������ (>>)\n"\
            " 6-���������� �������� �������� (~)\n"\
            " 7-��������� ���������� ���������\n");
}

void IPrinter::printMessage(const char *message) {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;
    (*out) << message;
}

void IPrinter::printMessage(int num) {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;
    (*out) << num;
}

class ConsolePrinter : public IPrinter {
public:
protected:
    virtual ostream *getOutStream() override {
        return &cout;
    }
};

class FilePrinter : public IPrinter {
public:
    FilePrinter() {
        isOpenFile = false;
        try {

            file.open("./out", std::ofstream::out | std::ofstream::app);
            isOpenFile = true;
        }
        catch (std::ios_base::failure &e) {
            std::cerr << e.what() << '\n';
        }
    }

    ~FilePrinter() {
        (file).close();
    }

protected:
    ofstream file;
    bool isOpenFile;

    virtual ostream *getOutStream() override {
        if (!isOpenFile)
            return nullptr;
        return &file;
    }
};

PrintComposer *PrintComposer::addConsolePrinter() {
    return add(new ConsolePrinter());
}

PrintComposer *PrintComposer::addFilePrinter() {
    IPrinter *printer;
    printer = new FilePrinter();
    return add(printer);
}

void PrintComposer::printMessage(const char *message) {
    for (auto i:printers)
        i->printMessage(message);
}

void PrintComposer::printMessage(int num) {
    for (auto i:printers)
        i->printMessage(num);
}

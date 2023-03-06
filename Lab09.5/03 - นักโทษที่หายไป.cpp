/*
[C++]

ณ เรือนจำแห่งหนึ่ง มีการระบุตัวนักโทษ โดยใช้หมายเลขจำนวนเต็มบวกแทนชื่อของนักโทษ เริ่มตั้งแต่หมายเลข 1, 2, 3, ..., n หมายเลขจะแปะอยู่ที่เสื้อของนักโทษ

ทุกเช้าจะมีการเช็คชื่อ โดยใช้กล้องสแกนหมายเลขบนเสื้อของนักโทษ ให้นิสิตหาว่านักโทษหมายเลขใดหายไปจากการเช็คชื่อในเช้าวันนี้บ้าง

ข้อมูลเข้า
    บรรทัดแรก เป็นจำนวนของนักโทษ ที่กล้องสามารถสแกนหมายเลขบนเสื้อได้
    บรรทัดต่อมา เป็นหมายเลขที่กล้องสามารถสแกนได้ คั่นแต่ละหมายเลขด้วยช่องว่าง โดยนักโทษหมายเลข n จะถูกสแกนได้เสมอ
ข้อมูลออก
    บรรทัดแรก แสดงหมายเลขของนักโทษที่หายไป เฉพาะหมายเลขคี่ เรียงตามลำดับจากน้อยไปมาก คั่นด้วยช่องว่าง
    บรรทัดที่สอง แสดงหมายเลขของนักโทษที่หายไป เฉพาะหมายเลขคู่ เรียงตามลำดับจากน้อยไปมาก คั่นด้วยช่องว่าง
ตัวอย่างข้อมูลเข้า/ข้อมูลออก
    15
    7 1 4 18 9 3 8 2 5 14 20 19 12 11 13
    15 17 
    6 10 16
*/

#include<iostream>
#define INT_MIN -2147483647
#define INT_MAX 2147483647
using namespace std;

int main() {
    int n, max = INT_MIN, min = INT_MAX, not_found[50];
    int find_num, size, pos = 0;
    int foundFlag = 1;
    cin >> n;
    int nums[n];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // find min max
    for (int j = 0; j < n; j++) {
        if (nums[j] > max) {
            max = nums[j];
        }
        if (nums[j] < min) {
            min = nums[j];
        }
    }

    // find size of numbers that are not found inside nums array
    for (int i = 1; find_num <= max; i++) {
        // for each iteration inside nums array
        for (int array_n = 0; array_n < n; array_n++) {
            if (i == nums[array_n]) {
                foundFlag = 0;
            }
        }
        if (foundFlag) {
            not_found[pos] = find_num;
            pos++;
            size++;
        }
        foundFlag = 1;
    }

    for (int i = 0; i < size; i++) {
        if (not_found[i] % 2 != 0) {
            cout << not_found[i] << " ";
        }
    }
    cout << "\n";

    for (int j = 0; j < size; j++) {
        if (not_found[j] % 2 == 0) {
            cout << not_found[j] << " ";
        }
    }
}
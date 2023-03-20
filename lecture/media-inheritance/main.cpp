/*
references:
    Makefile: https://kasets.art/W93AZ5 
    C++ Inheritance: https://kasets.art/UCfFTL
    Slides: https://docs.google.com/presentation/d/1HaQv75QR5jusidPgKl0fN2fGMiONLKaZ_q7rDCBOB0s/

# คำถามท้ายบท
1. method `Image::info()` และ `Video::info()` มีบางโค้ดบางส่วนเหมือนกัน
จะใช้หลักการ DRY มาลดความซ้ำซ้อนของโค้ดที่ซ้ำกันใน 2 method นี้อย่างไร
2. method `Image::toScreen()` และ `Video::toScreen()` มีการทำงานที่แตกต่างกัน
แต่มี prototype เหมือนกัน จะใช้หลักการ DRY มาลดความซ้ำซ้อนของ 2 method นี้ได้หรือไม่ อย่างไร
3. โค้ดต่อไปนี้ นำไป compile และ run ได้
    Media* imageMedia = new Image("frame.jpg", 3248303, 12, 7, '<', '>');
    compile ได้ run ได้ แต่ไม่ออกค่าเพราะไม่ได้ print

    3.1 instance `imageMedia` เรียก method ใดได้บ้าง และผลลัพธ์เป็นอย่างไร
    
    3.2 instance `imageMedia` เรียก method ใดไม่ได้บ้าง
    
4. โค้ดต่อไปนี้ นำไป compile และ run ได้
    
    ```cpp
    Media* videoMedia = new Video("clip.mp4", 3248303, 24923);
    ```
    
    4.1 instance `videoMedia` เรียก method ใดได้บ้าง และผลลัพธ์เป็นอย่างไร
    
    4.2 instance `videoMedia` เรียก method ใดไม่ได้บ้าง
    
    4.3 method ที่ instance `videoMedia` เรียกได้ เหมือนหรือต่างจากที่ instance `imageMedia` เรียกได้ อย่างไร
*/

#include <iostream>
#include "Media.h"
#include "Image.h"
#include "Video.h"
using namespace std;

int main() {
    // tests
    // 3.
    Media* imageMedia = new Image("frame.jpg", 3248303, 12, 7, '<', '>');
    cout << imageMedia->getTitle() << "\n";
    cout << imageMedia->getSizeInBytes() << "\n";
    cout << imageMedia->getSizeInKB() << "\n";
    cout << imageMedia->getSizeInMB() << "\n";
    cout << imageMedia->getSizeInGB() << "\n\n";

    // 4.
    Media* videoMedia = new Video("clip.mp4", 3248303, 24923);
    cout << videoMedia->getTitle() << "\n";
    cout << videoMedia->getSizeInBytes() << "\n";
    cout << videoMedia->getSizeInKB() << "\n";
    cout << videoMedia->getSizeInMB() << "\n";
    cout << videoMedia->getSizeInGB() << "\n";

    // Media *media = new Media("media", 811200000);
    // cout << media->getTitle() << endl;
    // cout << media->getSizeInBytes() << endl;
    // cout << media->getSizeInKB() << endl;
    // cout << media->getSizeInMB() << endl;
    // cout << media->getSizeInGB() << endl;
    // cout << "--------------------" << endl;

    // Image *image = new Image("hole.jpg", 4304, 11, 8, '{', '}');
    // cout << image->getTitle() << endl;
    // cout << image->getWidth() << endl;
    // cout << image->getHeight() << endl;
    // cout << image->getSizeInBytes() << endl;
    // cout << image->getSizeInKB() << endl;
    // cout << image->getSizeInMB() << endl;
    // cout << image->getSizeInGB() << endl;
    // cout << image->info() << endl;
    // cout << image->toScreen() << endl;
    // cout << "-----------------------" << endl;

    // Video *video = new Video("cat.mp4", 532314442, 8000);
    // cout << video->getTitle() << endl;
    // cout << video->getDuration() << endl;
    // cout << video->durationToString() << endl;
    // cout << video->getSizeInBytes() << endl;
    // cout << video->getSizeInGB() << endl;
    // cout << video->info() << endl;
    // cout << video->toScreen() << endl;
}
# Đồ án 2 ET-HUST
## Đề tài
  Sử dụng vi điều khiển Atmega 16a đọc dữ liệu từ cảm biến nhiệt độ LM35 và hiển thị lên LCD 1602
  
## Linh kiện
  - Kit phát triển cho vi điều khiển AVR
  - Vi điều khiển: Atmega 16a
  - Cảm biến nhiệt độ LM35
  - LCD 1602
  - Mạch nạp: USBASP V2.0
  - Test UART: Arduino Uno R3

## Tool
  - IDE: Microchip Studio 7.0
  - Flash firmware: proisp v1.72

## Nội dung
  - Lập trình thanh ghi để chuyển dữ liệu điện (Analog) từ cảm biến LM35 sang Digital
  - Hiển thị dữ liệu lên màn hình LCD bằng GPIO
  - Test truyền dữ liệu đó qua UART bằng cách sử dụng Arduino để nhận tín hiệu UART

## Note
  - Link tải proisp v1.72: https://drive.google.com/drive/folders/1csWaznXzu6ZksiaAki_OtagzW5f9LZvh
  - Hướng dẫn cài driver mạch nạp USBASP V2.0: https://www.instructables.com/USBASP-Installation-in-Windows-10/
  - Hàn jump và cắm connector và JP3 của mạch nạp
  - Không chỉnh fuse bit mà không biết trước ý nghĩa vì có thể đưa vđk vào trạng thái đặc biệt (vd: không có nguồn tạo dao động để hoạt động, không enable SPI,...)

## Fuse bit ví dụ (áp dụng với dùng dao động ngoài 8MHz)
![image](https://github.com/user-attachments/assets/d55233b2-f2ae-419f-bd6f-09b29efb687c)



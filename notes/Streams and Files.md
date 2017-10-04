## **Streams and Files**

#### **C++**

```cpp
  std::fstream ioFile; // stream to read and write

  ioFile.open("input.txt", std::ios::in); // specifying fstream to read

  ioFile.open("output.txt", std::ios::out, std::ios::app); // app appends output
  ioFile.open("input.txt", std::ios::in, std::ios::ate); // ate sets the read position in input

  ioFile.close();

```

#### **Java**

AAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHH

This is not buffered.

```java
  FileInputStream fin = new FileInputStream("file.dat");
  DataInputStream din = new DataInputStream(fin);
  Double s = din.readDouble();
```

This is buffered.

```java
DataInputStream din = new DataInputStream (new BufferedInputStream(newFileInputStream("file.dat")));
```

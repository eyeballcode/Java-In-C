#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class String {
    char* value;
    public:
      String(char* value) {
        this->value = value;
      }
      String(const char* value) {
        this->value = (char*) value;
      }
      char* chrValue() { return this->value; };     
      int length() { return strlen(value) - 1; }
      String substring(int start, int end) {
         int length = end - start;
         char buffer[length + 1];
         for (char* x = value + start; x < value + length; x++) {
           printf("%c", *(x));
         }
         buffer[length + 1] = '\0';
         printf("%s\n", buffer);
         return String(buffer);
      }
};

class Integer_ {
    public:
        int parseInt(String int_) {
            return atoi(int_.chrValue());
        }
};

struct PrintStream {
    void println(const char* chars) {
       printf("%s\n", chars);
    }
   
    void println(int data) {
	printf("%i\n", data);
    }

    void println(String str) {
       printf("%s\n", str.chrValue());
    }

    void print(const char* chars) {
        printf("%s", chars);
    }
    
    void print(String str) {
        printf("%s", str.chrValue());
    }
    void print(int data) {
        printf("%i", data);
    }
};

class InputStream {
    public:
      char read() {
          int data = getchar();
          return data;
      }
};

class Reader {
  public:
    char read() {
      return 0;
    }

};

class BufferedReader : public Reader {
  Reader base;
  public:
    BufferedReader(Reader base) {
      this->base = base;
    }
    
    char read() {
      return base.read();
    }
    String readLine() {
      char *line = (char *) malloc(100), *linep = line;
      size_t lenmax = 100, len = lenmax;
      int c;

      if(line == NULL)
	  return String("");

      for(;;) {
	  c = fgetc(stdin);
	  if(c == EOF)
	      break;

	  if(--len == 0) {
	      len = lenmax;
	      char *linen = (char *) realloc(linep, lenmax *= 2);

	      if(linen == NULL) {
		  free(linep);
		  return String("");
	      }
	      line = linen + (line - linep);
	      linep = linen;
	  }

	  if((*line++ = c) == '\n')
	      break;
      }
      *line = '\0';
      String val = String(linep);
      return val;
    }
};

class InputStreamReader : public Reader {
  InputStream in;
  public:
    InputStreamReader(InputStream in) {
      this->in = in;
    }
    char read() {
      return this->in.read();
    }
};

struct System_ {
  PrintStream out;
  InputStream in;
};

static System_ System;
static Integer_ Integer;


#define main(String) main(int, char**)

#define void int
#define public
#define static
#define new 

public static void main(String[] args) {
  System.out.println("Hello world!");
  System.out.print("Say something:   ");
  BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
  String line = reader.readLine();
  System.out.println("You said: ");
  System.out.println(line);
  System.out.print("That was ");
  System.out.print(line.length());
  System.out.print(" chars.");
  System.out.println("Numbers 1 to 10:");
  for (int i = 1; i <= 10; i++) {
    System.out.println(i);
  }
  System.out.print("Enter a start: ");
  int start = Integer.parseInt(reader.readLine());
  System.out.print("Enter an end: ");
  int end = Integer.parseInt(reader.readLine());
  System.out.println(line.substring(start, end));
}

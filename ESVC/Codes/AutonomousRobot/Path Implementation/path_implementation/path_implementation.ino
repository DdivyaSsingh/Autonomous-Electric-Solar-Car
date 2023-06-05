void pathImplementation(String path) {

  int n = path.length();

  for (int i = 0; i < n; i++) {

    char current = path.charAt(i);

    if (i == 0) {

      if (current == 'L') {
        anticlockRotate();
      } else if (current == 'R') {
        clockRotate();
      } else if (current == 'U') {
        anticlockRotate();
      }

    }

    else if (path.charAt(i) != path.charAt(i - 1)) {

      char previous = path.charAt(i - 1);

      if (current == 'U') {
        if (previous == 'L') {
          anticlockRotate();
        } else {
          clockRotate();
        }
      }

      else if (current == 'D') {
        if (previous == 'L') {
          clockRotate();
        } else {
          anticlockRotate();
        }
      }

      else if (current == 'R') {
        if (previous == 'U') {
          anticlockRotate();
        } else {
          clockRotate();
        }
      } else if (current == 'L') {
        {
          if (previous == 'U') {
            clockRotate();
          } else {
            anticlockRotate();
          }
        }
      }
    }

    mover();

  }
}


void setup() {
  // put your setup code here, to run once:

  pathImplementation("DRRRDDD");

}

void loop() {
  // put your main code here, to run repeatedly:
}

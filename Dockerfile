FROM gcc:latest
WORKDIR /usr/src/myapp
COPY . /usr/src/myapp/
RUN gcc -o myapp Tower_OF_Hanoi3.cpp -lstdc++
CMD "./myapp"
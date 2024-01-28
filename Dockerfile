FROM gcc:latest
WORKDIR /usr/src/myapp
COPY . /usr/src/myapp/
FROM --platform=linux/arm64 arm64v8/debian:11-slim  AS deps
RUN ls /
RUN g++ -o myapp Tower_OF_Hanoi3.cpp -lstdc++

CMD ["./myapp"]
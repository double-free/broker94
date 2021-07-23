FROM gcc:latest

RUN apt-get update && apt-get install -y libgtest-dev 

COPY . /usr/broker94
WORKDIR /usr/broker94/test

RUN make

CMD ["/bin/bash"]

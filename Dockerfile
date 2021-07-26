FROM gcc:latest

RUN apt-get update && apt-get install -y libgtest-dev && apt-get install -y less

COPY . /usr/broker94
WORKDIR /usr/broker94/test

RUN make -j8

CMD ["/bin/bash"]

oes_tester
===================

oes_tester 是交易端的测试工具，可以发送委托、接收回报和查询数据。配置文件是目录下的 oes_tester.conf，配置方式和API配置文件相同。

具体执行方式如下：

### 1. 打印提示信息

  ./oes_tester -h
  ./oes_tester arpt -h

  * 其中，arpt 是基于异步API接收回报数据的子命令，可用的子命令包括：
    - async-rpt (arpt) : 基于异步API接收回报数据
    - async-ord (aord) : 基于异步API发送委托请求
    - report (rpt)     : 基于同步API接收回报数据
    - order (ord)      : 基于同步API发送委托请求
    - cancel           : 基于同步API发送撤单请求
    - query (qry)      : 执行查询指令

### 2. 接收回报数据 (下面的命令会把回报数据输出到 XXX.txt 文件中，统计信息输出到 stats.txt 文件中)

  ./oes_tester arpt -oXXX.txt -Ostats.txt


mds_tester
===================

mds_tester 是对接和落地行情数据的工具。配置文件是目录下的 mds_tester.conf，配置方式和API配置文件相同。

具体执行方式如下：

### 1. 打印提示信息

  ./mds_tester -h
  ./mds_tester atcp -h

  * 其中，atcp 是基于异步API对接TCP行情的子命令，可用的子命令包括：
    - async-tcp (atcp) : 基于异步API对接TCP行情
    - async-udp (audp) : 基于异步API对接UDP组播行情
    - query (qry)      : 执行查询指令
    - tcp-mktdt (tcp)  : 基于同步API对接TCP行情
    - udp-mktdt (udp)  : 基于同步API对接UDP组播行情

### 2. 对接和落地行情数据（以CSV格式输出到 mkdata.csv 文件中，统计信息输出到 stats.txt 文件中）

  ./mds_tester atcp -omkdata.csv -Ostats.txt --csv

### 3. 只统计行情延迟，不落地行情数据

  ./mds_tester atcp

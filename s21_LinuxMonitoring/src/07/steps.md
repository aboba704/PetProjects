### Добавь на дашборд Grafana отображение ЦПУ, доступной оперативной памяти, свободное место и кол-во операций ввода/вывода на жестком диске.

#### Disk Usage: `container_fs_usage_bytes{id="/"}`
#### Memory Usage: `container_memory_usage_bytes{id="/"}`
#### CPU Usage: `rate(container_cpu_usage_seconds_total{id="/"}[5m])`
#### Disk I/O: `rate(container_fs_writes_bytes_total{device="/dev/vdb", id="/"}[5m])`

disk usage использую как запись данных на диск из-за особенностей cadvisor

![img](img/image.png)

`docker compose down script-runner`

![img](img/image1.png)

`stress -c 2 -i 1 -m 1 --vm-bytes 32M -t 10s`

![img](img/image2.png)
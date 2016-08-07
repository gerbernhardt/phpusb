<?php

function wait(){
 while(true){
  $data=wapi_serial_read(1);
  if($data==1){
   return true;
  }elseif($data==2){   return false;
  }
 }
}

if(wapi_serial_connect("\\\\.\\COM3",'250000'))
 print 'connected...';
else print 'failed...';
print "\n";

// 0 1 2 1 X Y Z EXTRUSOR
$cmd='0121;';

$init=explode(' ',microtime());
$init=$init[0]+$init[1];

for($i=0;$i<400;$i++){
 wapi_serial_write($cmd);
 print $cmd;
 if(wait())
  print ' [OK]';
 else print '[FAIL]';
 print "\n";
}

$end=explode(' ',microtime());
$end=$end[0]+$end[1];
print substr($end-$init,0,5);

?>
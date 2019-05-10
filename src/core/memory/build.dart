import 'dart:io';
import 'dart:convert';

const TARGET_NAME = 'main';
const DEST_DIR = './bin';
const HEADERS = [
  'geometry.h'
];
const SOURCES = [
  'main.cpp',
  'geometry.cpp'
];

main(List<String> args) {
  if (args.length == 1) {
    if (args[0] == "run") {
      Process.run(DEST_DIR + '/' + TARGET_NAME + '.exe',[]).then((proc){
        print(proc.stdout.toString());
      });
      return;
    }
  }

  var now = DateTime.now();
  print("Now is: ${now.toString()}");

  var destDir = new Directory(DEST_DIR);
  if(!destDir.existsSync()) {
    destDir.createSync();
  }
  
  var hasNotFound = false;
  for(var src in SOURCES) {
    var srcFile = new File(src);
    if(!srcFile.existsSync()) {
      print("ERROR => source file: $src not exists, compile stoped!");
      hasNotFound = true;
      continue;
      // return;
    }
    print('found: $src');
  }

  if(!hasNotFound) {
    var args = ['-std=c++17'];
    args.addAll(SOURCES);
    args.add('-o');
    args.add(DEST_DIR + '/' + TARGET_NAME+'.exe');
    Process.start('g++',args).then((proc){
    proc.stdout.transform(utf8.decoder)
               .listen((data) { print(data); });
    });
  }
}

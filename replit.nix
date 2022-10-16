{ pkgs }: {
	deps = [
		pkgs.python38Packages.pwntools
  pkgs.valgrind
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}
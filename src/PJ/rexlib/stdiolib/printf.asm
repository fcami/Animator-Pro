	include stdiolib.i

CGROUP	group	code

code	segment dword 'CODE'
	assume cs:CGROUP,ds:CGROUP

STDIOLIB_JUMP printf siol_printf

code	ends
	end

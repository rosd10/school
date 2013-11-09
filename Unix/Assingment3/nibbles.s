# Constants

#Window size
WIDTH=40
HEIGHT=40

#Snake start
STARTX=20
STARTY=20

#Field Values
EMPTY=0
APPLE=1
DOWN=2
UP=3
LEFT=4
RIGHT=5
WALL=6

#Graphics
WALLCHAR=72 #'H'
APPLECHAR=64 #'@'
SNAKECHAR=70 #'F'
NOCHAR = 32 #' '

#Collision
COLLISSION=DOWN

#KEYS
UPKEY=119 #w
DOWNKEY=115 #s
RIGHTKEY=100 #d
LEFTKEY=97 #a
EXITKEY=27 # esc
OFFSETKEY= DOWNKEY - DOWN

#Variabler
.data
direction: .long RIGHT #Start dir
quit: .long 0

.bss
field: .space WIDTH*HEIGHT*4 # size of the fields in bytes
head: .long 0
tail: .long 0

.text

updateSnake:
	movl	8(%esp), %edx	#edx håller dir
	movl	4(%esp), %ecx	#address till index
	movl	(%ecx), %eax	# eax index

moveUp: #om direction är up flytta snake up, går vidare till moveDown annars
	cmpl	$UP, %edx
	jnp	moveDown
	decl	%eax
	jmp	print

moveDown: #om direction är ner flytta snake ner, går vidare till moveLeft annars
	cmpl	$UP, %edx
	jne	moveLeft
	incl	%eax
	jmp	print

moveLeft: #om direction är vänster flytta snake vänster, går vidare till moveRight annars
	cmpl	$UP, %edx
	jne	moveRight
	subl	$HEIGHT, %eax
	jmp	print

moveRight: #flytta snake höger
	addl	$HEIGHT,%eax

print: #kalla på nib_put_scr för att rita ut snake
	movl	%eax,(%ecx)
	pushl	12(%esp)
	xorl	%edx, %edx
	movl	$HEIGHT, %ecx
	idiv	%ecx
	pushl	%edx
	pushl	%eax
	call	nib_put_scr
	addl	$12, %esp
	ret

setFieldValue: #sätter ett nytt värde på en field possition
	movl	4(%esp), %eax
	imull	$HEIGHT, %eax
	addl	8(%esp), %eax
	movl	$field, %ecx
	movl	16(%esp), %edx
	movl	%edx, (%ecx, %eax, 4)
	ret
	
getFieldValue: #hämtar en field possition
	movl    4(%esp), %eax
        imull   $HEIGHT, %eax
        addl    8(%esp), %eax
        movl    $field, %ecx
        movl    (%ecx, %eax, 4), %edx
        ret

moveSnake: #denna funktionen updaterar snakes position samt kollar kollision med äpplen
        # Move head
        movl    (direction), %edx
        movl    $field, %esi
        movl    (head), %eax
        movl    %edx, (%esi, %eax, 4)

        pushl   $SNAKECHAR
        pushl   %edx
        pushl   $head

        call    updateSnake

        addl    $12, %esp

        movl    (head), %eax
        movl    (%esi, %eax, 4), %ebx
        cmpl    $APPLE, %ebx
        jne     noApple
        call    createApple
        jmp     checkCollision
		
noApple: # flyttar svansen på snake om man inte har ätit ett äpple
        movl    (tail), %eax
        movl    (%esi, %eax, 4), %edx
        movl    $EMPTY, (%esi, %eax, 4)
        
        pushl   $NOCHAR
        pushl   %edx
        pushl   $tail

        call    updateSnake

        addl    $12, %esp

checkCollision: #kollar om det är en kollision och stänger programmet
        cmpl    $COLLISSION, %ebx
        jl      checkDone
        movl    $1, (quit)

checkDone:
        ret
		
createApple: #skapar äpple
        subl    $12, %esp
appleLoop:

        call    rand

        xorl    %edx, %edx #nollställer edx
        movl    $WIDTH, %ecx
        idiv    %ecx           
        movl    %edx, (%esp)

        # Random y-coordinate
        call    rand
        xorl    %edx, %edx
        movl    $HEIGHT, %ecx
        idiv    %ecx
        movl    %edx, 4(%esp)

        call    getFieldValue

        cmpl    $EMPTY, %edx #om det finns fler äpple än $EMPTY så kör den vidare
        jne     appleLoop

        movl    $APPLE, (%ecx, %eax, 4)
        movl    $APPLECHAR, 8(%esp)
        call    nib_put_scr
        
        addl    $12, %esp
        ret
		
.globl start_game
start_game: #startar spelet
	enter $0,$0
	
	#setup stack and so on
	call nib_init #nib_init()
	subl    $16, %esp
printWall:
	movl $WALLCHAR,8(%esp)
	movl $WALL,16(%esp)
	
	movl $HEIGHT-2,%ebx
	
printWallVertical: #lägger till strukturen för de vertikala väggarna
	movl    $0, (%esp)
        movl    %ebx, 4(%esp)
        call    setFieldValue
        call    nib_put_scr
        movl    $WIDTH-1, (%esp)
        call    setFieldValue
        call    nib_put_scr
        decl    %ebx
        jg      printWallVertical
        
        movl    $WIDTH-1, %ebx

printWallHorizontal: #lägger till strukturen för de horisontella väggarna
        movl    %ebx, (%esp)
        movl    $0, 4(%esp)
        call    setFieldValue
        call    nib_put_scr
        movl    %ebx, (%esp)
        movl    $HEIGHT-1, 4(%esp)
        call    setFieldValue
        call    nib_put_scr
        decl    %ebx
        jge     printWallHorizontal
		
initSnake: #initialiserar masken
        movl    $STARTY, 4(%esp)
        movl    $SNAKECHAR, 8(%esp)
        movl    $RIGHT, 12(%esp)
	
        movl    $STARTX, %eax
        imull   $HEIGHT, %eax
        addl    $STARTY, %eax
        movl    %eax, (head)
        
        movl    $STARTX + 1, %ebx
        subl    8(%ebp), %ebx
        
        movl    %ebx, %eax
        decl    %eax
        imull   $HEIGHT, %eax
        addl    $STARTY, %eax
        movl    %eax, (tail)
        movl    $field, %ecx
        movl    $RIGHT, (%ecx, %eax, 4)

initSnakeLoop: #skriver ut ormen på skärmen
        movl    %ebx, (%esp)
        call    setFieldValue
        call    nib_put_scr
        incl    %ebx
        cmpl    $STARTX, %ebx
        jle     initSnakeLoop

        addl    $16, %esp

        movl    12(%ebp), %ebx
initApples: #startar skapandet av äpple
        call    createApple
        decl    %ebx
        jg      initApples
gameLoop: #main spel loop
        pushl   $100000
        call    usleep
        addl    $4, %esp

        call    nib_poll_kbd
keyQuit: #kollar om EXITKEY är nertryckt och om den är det stänger av spelet
        cmpl    $EXITKEY, %eax
        jne     keyMove
        movl    $1, (quit)
        jmp     keyCheckDone
keyMove: #kollar om någon av rörelseknapparna är nertryckt
        cmpl    $DOWNKEY, %eax
        jl      keyCheckDone
        cmpl    $RIGHTKEY, %eax
        jg      keyCheckDone
        subl    $OFFSETKEY, %eax
        movl    %eax, (direction)
keyCheckDone: #aggerar på knapptryckningar och om spelet skall avslutas
        call    moveSnake
        cmpl    $0, (quit)
        je      gameLoop
	call	nib_end #nib_end()
	leave
	ret

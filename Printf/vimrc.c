colorscheme default

set hidden " не выгружать буфер когда переключаешься на другой
set mouse=a " включает поддержку мыши при работе в терминале (без GUI)
set mousehide " скрывать мышь в режиме ввода текста
set showcmd " показывать незавершенные команды в статусбаре (автодополнение ввода)
set showmatch " показывать первую парную скобку после ввода второй
set t_Co=256 " использовать больше цветов в терминале

set list " включить подсветку
set listchars=tab:>-,trail:- " установить символы, которыми будет осуществляться подсветка
"Проблема красного на красном при spellchecking-е решается такой строкой в .vimrc
highlight SpellBad ctermfg=Black ctermbg=Red

au BufWinLeave *.* silent mkview " при закрытии файла сохранить 'вид'
au BufWinEnter *.* silent loadview " при открытии - восстановить сохранённый

set backspace=indent,eol,start " backspace обрабатывает отступы, концы строк
set sessionoptions=curdir,buffers,tabpages " опции сессий - перейти в текущую директорию, испол       ьзовать буферы и табы
set history=128 " хранить больше истории команд
let c_syntax_for_h="" " необходимо установить для того, чтобы *.h файлам присваивался тип c, а        не cpp
" При вставке фрагмента сохраняет отступ
" set pastetoggle=
"подсвечивает все слова, которые совпадают со словом под курсором.
autocmd CursorMoved * silent! exe printf("match Search /\\<%s\\>/", expand('<cword>'))

set ignorecase " ics - поиск без учёта регистра символов
set smartcase " - если искомое выражения содержит символы в верхнем регистре - ищет с учётом ре       гистра, иначе - без учёта
set nohlsearch " (не)подсветка результатов поиска (после того, как поиск закончен и закрыт)
set incsearch " поиск фрагмента по мере его набора
" поиск выделенного текста (начинать искать фрагмент при его выделении)
vnoremap <silent>* <ESC>:call VisualSearch()<CR>/<C-R>/<CR>
vnoremap <silent># <ESC>:call VisualSearch()<CR>?<C-R>/<CR>

"НАСТРОЙКИ СВОРАЧИВАНИЯ БЛОКОВ ТЕКСТА (фолдинг)
set foldenable " включить фолдинг
set foldmethod=syntax " определять блоки на основе синтаксиса файла
" set foldmethod=indent " определять блоки на основе отступов
set foldcolumn=3 " показать полосу для управления сворачиванием
set foldlevel=1 " Первый уровень вложенности открыт, остальные закрыты
set foldopen=all " автоматическое открытие сверток при заходе в них
set tags=tags\ $VIMRUNTIME/systags " искать теги в текущй директории и в указанной (теги генери       руются ctags)

"НАСТРОЙКИ РАБОТЫ С ФАЙЛАМИ
syntax on " включить подсветку синтаксиса
set number "  Показывать номера строк
set ruler " Показывать положение курсора всё время.

"НАСТРОЙКИ ОТСТУПА
" set tabstop=4 " ширина табуляции
" set shiftwidth=0
" set softtabstop=4 " ширина 'мягкого' таба
" set autoindent " ai - включить автоотступы (копируется отступ предыдущей строки)
" set cindent " ci - отступы в стиле С
" set expandtab " преобразовать табуляцию в пробелы
" set smarttab
" set smartindent " Умные отступы (например, автоотступ после {)
" set expandtab!
" filetype plugin indent on"

set list listchars=tab:→\ ,trail:·

" Показать невидимые символы"
"set listchars=tab:>-,trail:.,extends:>,precedes:<"
"set list"

" Ограничение символов в строке
set colorcolumn=80
highlight ColorColumn ctermbg=darkgray

"НАСТРОЙКИ ПЕРЕКЛЮЧЕНИЯ РАСКЛАДОК КЛАВИАТУРЫ
""" Взято у konishchevdmitry
" set keymap=russian-jcukenwin " настраиваем переключение раскладок клавиатуры по <C-^>
" set iminsert=0 " раскладка по умолчанию - английская
" set imsearch=0 " аналогично для строки поиска и ввода команд

filetype plugin on
set omnifunc=syntaxcomplete#Complete

" ВКЛЮЧЕНИЕ АВТОДОПЛНЕНИЯ ВВОДА (omnifunct)
autocmd FileType c set omnifunc=ccomplete#Complete

" Обертка для :make -->
" nmap ,m :call make<CR>
" nmap ,w :cwindow<CR>
" nmap ,n :cnext<CR>
" nmap ,p :cprevious<CR>
" nmap ,l :clist<CR>

" menu Make.Make<Tab>,m ,m
" menu Make.Make\ Window<Tab>,w ,w
" menu Make.Next\ Error<Tab>,n ,n
" menu Make.Previous\ Error<Tab>,p ,p
" menu Make.Errors\ List<Tab>,l ,l
" Обертка для :make <--

" Ctrl-пробел для автодополнения
" inoremap <C-space> <C-x><C-o>

" Следующим шагом добавим пару крайне полезных функций. Во-первых, небольшая
" доработка автодополенения. Смысл доработки сводится к тому, что функция
" автодопленение “вешается” на символ табуляции и в зависимости от того
" имеются ли в строке какие-либо символы или нет, вызывается автодополнение
" или просто добавляется символ табуляции.

function! SuperCleverTab()
    if strpart( getline('.'), 0, col('.')-1 ) =~ '^\s*$'
        return "\<Tab>"
    else
        return "\<C-p>"
    endif
endfunction


" inoremap <Tab> <C-R>=SuperCleverTab()<cr>

" New Plugin!
" set nocompatible              " be iMproved, required
" filetype off                  " required

" set the runtime path to include Vundle and initialize
" set rtp+=~/.vim/bundle/Vundle.vim
" call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
" call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
" Plugin 'VundleVim/Vundle.vim'

" call vundle#end()            " required
" filetype plugin indent on    " required

" Plugin 'Valloric/YouCompleteMe'
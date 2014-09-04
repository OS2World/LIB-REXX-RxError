/* Example of using RxError() function */
call RxFuncAdd 'RxError','RxError','RxError'

/*  Disable hard errors:

    'disableharderrors'
    'disableharderr'
    'disablehard'
    'dhard'
    'dh'
*/

call RxError 'dh'

/*  
    Attempt to change to the root directory of an invalid drive.
    If Z: is valid, substitute a letter that isn't, which may
    also be a CD drive that's empty or has a music CD in it.
*/

check=directory('Z:\')

if check='' then do
    say ''
    say 'Drive not ready.'
end

call RxError 'eh'

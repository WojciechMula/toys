function SwitchHeaderImpl()
  let extension = expand("%:e")

  if extension == "h" || extension == "hpp"
    let extensions = ["cpp", "cc"]
  elseif extension == "cpp" || extension == "cc"
    let extensions = ["h", "hpp"]
  else
    return
  endif

  var path = ""
  for ext in extensions
    let basename  = expand("%:r")
    let p = basename . "." . ext
    if filereadable(p) > 0
        let path = p
        break
    endif
  endfor

  if path != ""
    exec "tabnew " path
  else
    echo "Can't find corresponding file"
  endif
endfun

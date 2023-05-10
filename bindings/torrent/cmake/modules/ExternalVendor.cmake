include(FetchContent)
message("starting")
FetchContent_Declare(
    libtorrent
    GIT_REPOSITORY https://github.com/arvidn/libtorrent.git
    GIT_TAG 272828e1cc37b042dfbbafa539222d8533e99755
    )
    
    FetchContent_MakeAvailable(libtorrent)
    message("ending")
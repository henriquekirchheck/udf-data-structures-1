{
  perSystem =
    { pkgs, config, ... }:
    {
      devShells = {
        default =
          pkgs.callPackage
            (
              {
                mkShell,

                ninja,
                cmake,
                pkg-config,
                llvmPackages_22,

                treefmt-wrapper,
              }:
              (mkShell.override { stdenv = llvmPackages_22.stdenv; }) {
                packages = [
                  treefmt-wrapper
                  llvmPackages_22.clang-tools
                ];
                nativeBuildInputs = [
                  ninja
                  cmake
                  pkg-config
                ];
                buildInputs = [ ];
              }
            )
            {
              treefmt-wrapper = config.treefmt.build.wrapper;
            };
      };
    };
}
